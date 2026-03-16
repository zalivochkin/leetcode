
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        vector<vector<int>> s1(n + 1, vector<int>(m + 2));
        vector<vector<int>> s2(n + 1, vector<int>(m + 2));
        for (auto i = 1; i <= n; ++i) {
            for (auto j = 1; j <= m; ++j) {
                s1[i][j] = s1[i - 1][j - 1] + grid[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + grid[i - 1][j - 1];
            }
        }
        set<int> ss;
        for (auto i = 1; i <= n; ++i) {
            for (auto j = 1; j <= m; ++j) {
                int l = min({i - 1, static_cast<int>(n) - i, j - 1, static_cast<int>(m) - j});
                ss.insert(grid[i - 1][j - 1]);
                for (auto k = 1; k <= l; ++k) {
                    int a = s1[i + k][j] - s1[i][j - k];
                    int b = s1[i][j + k] - s1[i - k][j];
                    int c = s2[i][j - k] - s2[i - k][j];
                    int d = s2[i + k][j] - s2[i][j + k];
                    ss.insert(a + b + c + d - grid[i + k - 1][j - 1] + grid[i - k - 1][j - 1]);
                }
                while (ss.size() > 3) {
                    ss.erase(ss.begin());
                }
            }
        }
        return vector<int>(ss.rbegin(), ss.rend());
    }
};
