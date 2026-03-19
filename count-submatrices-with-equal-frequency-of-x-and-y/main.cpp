
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        vector<vector<vector<int>>> s(n + 1, vector<vector<int>>(m + 1, vector<int>(2)));
        int ans = 0;
        for (auto i = 1; i <= n; ++i) {
            for (auto j = 1; j <= m; ++j) {
                s[i][j][0] = s[i - 1][j][0] + s[i][j - 1][0] - s[i - 1][j - 1][0] + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                s[i][j][1] = s[i - 1][j][1] + s[i][j - 1][1] - s[i - 1][j - 1][1] + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
                if (s[i][j][0] > 0 && s[i][j][0] == s[i][j][1]) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
