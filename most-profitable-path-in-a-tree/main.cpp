
class Solution {
public:
    bool dfs1(vector<int> &ts, const vector<vector<int>> &graph, int i, int fa, int t) {
        if (i == 0) {
            ts[i] = t;
            return true;
        }
        for (const auto j : graph[i]) {
            if (j != fa && dfs1(ts, graph, j, i, t + 1)) {
                ts[j] = min(ts[j], t + 1);
                return true;
            }
        }
        return false;
    }
    
    void dfs2(const vector<int> &ts, const vector<vector<int>> &graph, const vector<int> &amount, int i, int fa, int t, int v, int &ans) {
        if (t == ts[i]) {
            v += amount[i] >> 1;
        } else if (t < ts[i]) {
            v += amount[i];
        }
        if (graph[i].size() == 1 && graph[i][0] == fa) {
            ans = max(ans, v);
            return;
        }
        for (const auto j : graph[i]) {
            if (j != fa) {
                dfs2(ts, graph, amount, j, i, t + 1, v, ans);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const auto n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (const auto &edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }
        vector<int> ts(n, n);
        dfs1(ts, graph, bob, -1, 0);
        ts[bob] = 0;
        int ans = INT_MIN;
        dfs2(ts, graph, amount, 0, -1, 0, 0, ans);
        return ans;
    }
};
