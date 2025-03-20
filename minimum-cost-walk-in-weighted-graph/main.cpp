
class UnionFind {
public:
    UnionFind(int n) : p{vector<int>(n)}, size{vector<int>(n, 1)} {
        iota(p.begin(), p.end(), 0);
    }

    bool unite(int a, int b) {
        const auto pa = find(a);
        const auto pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(int x) const {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int getSize(int x) {
        return size[find(x)];
    }

private:
    mutable vector<int> p;
    vector<int> size;
};

class Solution {
public:
    int f(const UnionFind &uf, const vector<int> &g, int u, int v) {
        if (u == v) {
            return 0;
        }
        int a = uf.find(u);
        int b = uf.find(v);
        return a == b ? g[a] : -1;
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> g(n, -1);
        UnionFind uf(n);
        for (const auto &edge : edges) {
            uf.unite(edge[0], edge[1]);
        }
        for (const auto &e : edges) {
            int root = uf.find(e[0]);
            g[root] &= e[2];
        }
        vector<int> ans;
        for (const auto &q : query) {
            ans.push_back(f(uf, g, q[0], q[1]));
        }
        return ans;
    }
};
