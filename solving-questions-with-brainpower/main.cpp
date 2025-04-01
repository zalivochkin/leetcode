
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const auto n = questions.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int j = i + questions[i][1] + 1;
            dp[i] = max(dp[i + 1], questions[i][0] + (j > n ? 0 : dp[j]));
        }
        return dp[0];
    }
};
