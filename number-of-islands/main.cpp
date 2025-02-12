
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int dirs[5] = {-1, 0, 1, 0, -1};
        grid[i][j] = '0';
        for (auto k = 0; k < 4; ++k) {
            int ki = i + dirs[k];
            int kj = j + dirs[k + 1];
            if (ki >= 0 && ki < grid.size() && kj >= 0 && kj < grid[0].size() && grid[ki][kj] == '1') {
                dfs(grid, ki, kj);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        const auto m = grid.size();
        const auto n = grid[0].size();
        int ans = 0;
        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
