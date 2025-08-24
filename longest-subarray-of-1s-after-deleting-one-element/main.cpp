
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const auto n = nums.size();
        vector<int> left(n + 1);
        vector<int> right(n + 1);
        for (auto i = 1; i <= n; ++i) {
            if (nums[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i]) {
                right[i] = right[i + 1] + 1;
            }
        }
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            ans = max(ans, left[i] + right[i + 1]);
        }
        return ans;
    }
};
