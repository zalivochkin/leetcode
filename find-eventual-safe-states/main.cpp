
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const auto n = graph.size();
        vector<int> indeg(n);
        vector<vector<int>> rg(n);
        queue<int> q;
        for (auto i = 0; i < n; ++i) {
            for (auto j : graph[i]) {
                rg[j].push_back(i);
            }
            indeg[i] = graph[i].size();
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int i;
        while (!q.empty()) {
            i = q.front();
            q.pop();
            for (auto j : rg[i]) {
                indeg[j] -= 1;
                if (indeg[j] == 0) {
                    q.push(j);
                }
            }
        }
        vector<int> res;
        for (i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
