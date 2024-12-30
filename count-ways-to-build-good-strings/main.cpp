
class Solution {
public:
    int dfs(vector<int> &dp, int i, int low, int high, int zero, int one) {
        if (i > high) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        long ans = i >= low;
        ans += dfs(dp, i + zero, low, high, zero, one) + dfs(dp, i + one, low, high, zero, one);
        ans %= static_cast<long>(1e9 + 7);
        dp[i] = ans;
        return ans;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return dfs(dp, 0, low, high, zero, one);
    }
};
