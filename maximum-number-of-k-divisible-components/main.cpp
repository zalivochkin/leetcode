
class Solution {
public:
    long long dfs(vector<int> &values, int &ans, int k, vector<vector<int>> &g, int i, int fa) {
        long long s = values[i];
        for (auto j: g[i]) {
            if (j != fa) {
                s += dfs(values, ans, k, g, j, i);
            }
        }
        ans += (s % k == 0);
        return s;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        int ans = 0;
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        dfs(values, ans, k, g, 0, -1);
        return ans;
    }
};
