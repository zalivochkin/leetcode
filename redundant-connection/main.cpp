
class Solution {
public:
    int find(vector<int> &p, int x) {
        return x == p[x] ? x : p[x] = find(p, p[x]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> p(edges.size());
        iota(p.begin(), p.end(), 0);
        int pa, pb;
        for (auto i = 0;; ++i) {
            pa = find(p, edges[i][0] - 1);
            pb = find(p, edges[i][1] - 1);
            if (pa == pb) {
                return edges[i];
            }
            p[pa] = pb;
        }
    }
};
