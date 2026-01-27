
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w * 2);
        }

        const int inf = numeric_limits<int>::max() / 2;
        vector<int> dist(n, inf);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            if (u == n - 1) {
                return d;
            }

            for (auto& [v, w] : g[u]) {
                int nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.emplace(nd, v);
                }
            }
        }
        return -1;
    }
};
