
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0;
        for (auto num : nums) {
            num %= k;
            for (auto j = 0; j < k; ++j) {
                int y = (j - num + k) % k;
                dp[num][y] = dp[y][num] + 1;
                ans = max(ans, dp[num][y]);
            }
        }
        return ans;
    }
};
