
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const auto n = nums.size();
        vector<int> dp(32, -1);
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; --i) {
            int t = 1;
            for (auto j = 0; j < 32; ++j) {
                if ((nums[i] >> j) & 1) {
                    dp[j] = i;
                } else if (dp[j] != -1) {
                    t = max(t, dp[j] - i + 1);
                }
            }
            ans[i] = t;
        }
        return ans;
    }
};
