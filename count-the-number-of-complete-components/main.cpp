
class Solution {
public:
    pair<int, int> dfs(const vector<vector<int>> &graph, vector<bool> &visited, int i) {
        visited[i] = true;
        int edges_cnt = 1;
        int nodes_cnt = graph[i].size();
        for (const auto edge : graph[i]) {
            if (!visited[edge]) {
                auto [a, b] = dfs(graph, visited, edge);
                edges_cnt += a;
                nodes_cnt += b;
            }
        }
        return make_pair(edges_cnt, nodes_cnt);
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        for (const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            if (!visited[i]) {
                auto [m, edges_cnt] = dfs(graph, visited, i);
                if (m * (m - 1) == edges_cnt) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
