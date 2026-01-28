
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int half_inf = numeric_limits<int>::max() / 2;
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m, vector<int>(n, half_inf)));
        dp[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    dp[0][i][j] = min(dp[0][i][j], dp[0][i - 1][j] + grid[i][j]);
                }
                if (j > 0) {
                    dp[0][i][j] = min(dp[0][i][j], dp[0][i][j - 1] + grid[i][j]);
                }
            }
        }
        unordered_map<int, vector<pair<int, int>>> g;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = grid[i][j];
                g[x].emplace_back(i, j);
            }
        }
        vector<int> keys;
        keys.reserve(g.size());
        for (auto& e : g) {
            keys.push_back(e.first);
        }
        sort(keys.begin(), keys.end(), greater<>());
        for (int t = 1; t <= k; t++) {
            int mn = half_inf;
            for (int key : keys) {
                auto& pos = g[key];
                for (auto& p : pos) {
                    mn = min(mn, dp[t - 1][p.first][p.second]);
                }
                for (auto& p : pos) {
                    dp[t][p.first][p.second] = mn;
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i > 0) {
                        dp[t][i][j] = min(dp[t][i][j], dp[t][i - 1][j] + grid[i][j]);
                    }
                    if (j > 0) {
                        dp[t][i][j] = min(dp[t][i][j], dp[t][i][j - 1] + grid[i][j]);
                    }
                }
            }
        }
        int ans = half_inf;
        for (int t = 0; t <= k; t++) {
            ans = min(ans, dp[t][m - 1][n - 1]);
        }
        return ans;
    }
};
