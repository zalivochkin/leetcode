
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        auto n = days.back();
        int dp[n + 1];
        dp[0] = 0;
        int valid[3] = {1, 7, 30};
        int c;
        int v;
        for (auto i = 1, j = 0; i <= n; ++i) {
            if (i == days[j]) {
                dp[i] = INT_MAX;
                for (auto k = 0; k < 3; ++k) {
                    c = costs[k];
                    v = valid[k];
                    dp[i] = min(dp[i], dp[max(0, i - v)] + c);
                }
                ++j;
            } else {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};
