
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ranges::sort(nums);
        vector<int> dp(nums.size(), 1);
        int max_len = 1;
        int max_idx = 0;
        const auto n = nums.size();
        for (auto i = 1; i < n; i++) {
            for (auto j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] > max_len) {
                        max_len = dp[i];
                        max_idx = i;
                    }
                }
            }
        }
        int m = dp[max_idx];
        vector<int> ans;
        for (auto i = max_idx; m > 0; --i) {
            if (nums[max_idx] % nums[i] == 0 && dp[i] == m) {
                ans.push_back(nums[i]);
                max_idx = i;
                --m;
            }
        }
        return ans;
    }
};
