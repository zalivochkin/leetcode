
class Solution {
public:
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, int i, int j) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        const auto l = dirs.size();
        int res = grid[i][j];
        visited[i][j] = true;
        for (auto k = 0; k < l; ++k) {
            int ki = i + dirs[k][0];
            int kj = j + dirs[k][1];
            if (ki >= 0 && ki < n && kj >= 0 && kj < m && grid[ki][kj] > 0 && !visited[ki][kj]) {
                res += dfs(grid, visited, ki, kj);
            }
        }
        return res;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        int res = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j] > 0) {
                    vector<vector<bool>> visited(n, vector<bool>(m, false));
                    res = max(res, dfs(grid, visited, i, j));
                }
            }
        }
        return res;
    }
};
