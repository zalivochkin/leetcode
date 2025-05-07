
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const auto n = moveTime.size();
        const auto m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0});
        vector<int> dirs{-1, 0, 1, 0, -1};
        int ik;
        int jk;
        while (true) {
            auto [d, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1) {
                return d;
            }
            if (d > dist[i][j]) {
                continue;
            }
            for (auto k = 0; k < 4; ++k) {
                ik = i + dirs[k];
                jk = j + dirs[k + 1];
                if (ik >= 0 && ik < n && jk >= 0 && jk < m) {
                    int t = max(moveTime[ik][jk], dist[i][j]) + 1;
                    if (dist[ik][jk] > t) {
                        dist[ik][jk] = t;
                        pq.push({t, ik, jk});
                    }
                }
            }
        }
    }
};
