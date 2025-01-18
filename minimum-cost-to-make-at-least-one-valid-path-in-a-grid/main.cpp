
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<vector<int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        deque<pair<int, int>> q;
        q.emplace_back(0, 0);
        int i, j, x, y;
        while (!q.empty()) {
            auto p = q.front();
            q.pop_front();
            i = p.first / m;
            j = p.first % m;
            if (i == n - 1 && j == m - 1) {
                return p.second;
            }
            if (vis[i][j]) {
                continue;
            }
            vis[i][j] = true;
            for (auto k = 1; k <= 4; ++k) {
                x = i + dirs[k][0];
                y = j + dirs[k][1];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (grid[i][j] == k) {
                        q.emplace_front(x * m + y, p.second);
                    } else {
                        q.emplace_back(x * m + y, p.second + 1);
                    }
                }
            }
        }
        return -1;
    }
};
