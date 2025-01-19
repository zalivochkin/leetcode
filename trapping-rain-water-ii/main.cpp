
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const auto n = heightMap.size();
        const auto m = heightMap[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push(vector<int>{heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        vector<int> dirs{-1, 0, 1, 0, -1};
        int x, y;
        int res = 0;
        while (!pq.empty()) {
            const auto p = pq.top();
            pq.pop();
            for (auto k = 0; k < 4; ++k) {
                x = p[1] + dirs[k];
                y = p[2] + dirs[k + 1];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    visited[x][y] = true;
                    res += max(0, p[0] - heightMap[x][y]);
                    pq.push(vector<int>{max(p[0], heightMap[x][y]), x, y});
                }
            }
        }
        return res;
    }
};
