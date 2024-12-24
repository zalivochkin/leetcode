
class Solution {
public:
    void dfs(int &a, vector<int> *g, int &ans, int i, int fa, int t) {
        for (auto j : g[i]) {
            if (j != fa) {
                dfs(a, g, ans, j, i, t + 1);
            }
        }
        if (ans < t) {
            ans = t;
            a = i;
        }
    }

    int treeDiameter(vector<vector<int>>& edges) {
        const auto n = edges.size() + 1;
        vector<int> g[n];
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 0;
        int a = 0;
        dfs(a, g, ans, 0, -1, 0);
        dfs(a, g, ans, a, -1, 0);
        return ans;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = treeDiameter(edges1);
        int d2 = treeDiameter(edges2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};
