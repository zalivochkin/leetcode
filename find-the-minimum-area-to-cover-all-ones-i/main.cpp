
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        int x1 = n;
        int y1 = m;
        int x2 = 0;
        int y2 = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    x1 = min(x1, i);
                    y1 = min(y1, j);
                    x2 = max(x2, i);
                    y2 = max(y2, j);
                }
            }
        }
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
};
