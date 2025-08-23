
class Solution {
public:
    int fun(const vector<vector<int>>& grid, int i1, int j1, int i2, int j2) {
        const auto inf = numeric_limits<int>::max() / 4;
        int x1 = inf;
        int y1 = inf;
        int x2 = -inf;
        int y2 = -inf;
        for (int i = i1; i <= i2; i++) {
            for (int j = j1; j <= j2; j++) {
                if (grid[i][j] == 1) {
                    x1 = min(x1, i);
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                }
            }
        }
        return x1 > x2 || y1 > y2 ? inf : (x2 - x1 + 1) * (y2 - y1 + 1);
    }

    int minimumSum(vector<vector<int>>& grid) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        int ans = n * m;
        int inf = INT_MAX / 4;
        for (auto i1 = 0; i1 < n - 1; i1++) {
            for (auto i2 = i1 + 1; i2 < n - 1; i2++) {
                ans = min(ans, fun(grid, 0, 0, i1, m - 1) + fun(grid, i1 + 1, 0, i2, m - 1) + fun(grid, i2 + 1, 0, n - 1, m - 1));
            }
        }
        for (auto j1 = 0; j1 < m - 1; j1++) {
            for (auto j2 = j1 + 1; j2 < m - 1; j2++) {
                ans = min(ans, fun(grid, 0, 0, n - 1, j1) + fun(grid, 0, j1 + 1, n - 1, j2) + fun(grid, 0, j2 + 1, n - 1, m - 1));
            }
        }
        for (auto i = 0; i < n - 1; i++) {
            for (auto j = 0; j < m - 1; j++) {
                ans = min(ans, fun(grid, 0, 0, i, j) + fun(grid, 0, j + 1, i, m - 1) + fun(grid, i + 1, 0, n - 1, m - 1));
                ans = min(ans, fun(grid, 0, 0, i, m - 1) + fun(grid, i + 1, 0, n - 1, j) + fun(grid, i + 1, j + 1, n - 1, m - 1));
                ans = min(ans, fun(grid, 0, 0, i, j) + fun(grid, i + 1, 0, n - 1, j) + fun(grid, 0, j + 1, n - 1, m - 1));
                ans = min(ans, fun(grid, 0, 0, n - 1, j) + fun(grid, 0, j + 1, i, m - 1) + fun(grid, i + 1, j + 1, n - 1, m - 1));
            }
        }
        return ans;
    }
};
