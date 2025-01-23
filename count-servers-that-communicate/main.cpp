
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        vector<int> row(n);
        vector<int> col(m);
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        int res = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    ++res;
                }
            }
        }
        return res;
    }
};
