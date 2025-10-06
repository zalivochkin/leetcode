
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const auto n = grid.size();
        vector<int> dist(n * n, INT_MAX);
        dist[0] = grid[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.emplace(vector<int>{grid[0][0], 0, 0});
        const vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<bool> visited(n * n, false);
        visited[0] = true;
        int x, x_, y, y_, w, w_, max_w, indx;
        while (!pq.empty()) {
            w = pq.top()[0];
            x = pq.top()[1];
            y = pq.top()[2];
            pq.pop();
            if (x == n - 1 && y == n - 1) {
                return w;
            }
            for (auto [x_inc, y_inc] : dirs) {
                x_ = x + x_inc;
                y_ = y + y_inc;
                if (x_ < 0 || x_ == n || y_ < 0 || y_ == n) {
                    continue;
                }
                indx = x_ + y_ * n;
                if (visited[indx]) {
                    continue;
                }
                w_ = grid[y_][x_];
                max_w = max(w, w_);
                if (max_w < dist[indx]) {
                    dist[indx] = max_w;
                    pq.emplace(vector<int>{max_w, x_, y_});
                    visited[indx] = true;
                }
            }
        }
        return -1;
    }
};
