
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dist(n);
        iota(dist.begin(), dist.end(), 0);
        vector<vector<int>> adj(n);
        for (auto i = 0; i < n - 1; ++i) {
            adj[i].push_back(i + 1);
        }
        const auto m = queries.size();
        vector<int> res(m);
        int idx;
        for (auto i = 0; i < m; ++i) {
            adj[queries[i][0]].push_back(queries[i][1]);
            if (dist[queries[i][0]] + 1 < dist[queries[i][1]]) {
                queue<int> q;
                q.push(queries[i][1]);
                dist[queries[i][1]] = dist[queries[i][0]] + 1;
                while (!q.empty()) {
                    idx = q.front();
                    q.pop();
                    for (auto v : adj[idx]) {
                        if (dist[idx] + 1 < dist[v]) {
                            dist[v] = dist[idx] + 1;
                            q.push(v);
                        }
                    }
                }
            }
            res[i] = dist.back();
        }
        return res;
    }
};
