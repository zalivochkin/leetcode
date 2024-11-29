
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[1][0] <= 1 || grid[0][1] <= 1) {
            const vector<int> d{0, 1, 0, -1, 0};
            const auto n = grid.size();
            const auto m = grid[0].size();
            vector<vector<int>> time(n, vector<int>(m, INT_MAX));
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
            pq.emplace(0, 0, 0);
            time[0][0] = 0;
            while (!pq.empty()) {
                auto [t, i, j] = pq.top();
                pq.pop();
                if (i == n - 1 && j == m - 1) {
                    return t;
                }
                for (auto k = 0; k < 4; ++k) {
                    int r = i + d[k];
                    int s = j + d[k + 1];
                    if (r < 0 || r >= n || s < 0 || s >= m) {
                        continue;
                    }
                    bool w = !((grid[r][s] - t) & 1);
                    int nextTime = max(t + 1, grid[r][s] + w);
                    if (nextTime < time[r][s]) {
                        time[r][s] = nextTime;
                        pq.emplace(nextTime, r, s);
                    }
                }
            }
        }
        return -1;
    }
};
