
class BinaryIndexedTree {
private:
    int inf = 1 << 30;
    int n;
    vector<int> c;

public:
    explicit BinaryIndexedTree(int n) : n{n} {
        c.resize(n + 1, inf);
    }

    void update(int x, int v) {
        while (x <= n) {
            c[x] = min(c[x], v);
            x += x & -x;
        }
    }

    int query(int x) {
        int mi = inf;
        while (x > 0) {
            mi = min(mi, c[x]);
            x -= x & -x;
        }
        return mi == inf ? -1 : mi;
    }
};

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int> > &queries) {
        auto n = heights.size();
        auto m = queries.size();
        for (auto& q : queries) {
            if (q[0] > q[1]) {
                swap(q[0], q[1]);
            }
        }
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return queries[j][1] < queries[i][1];
        });
        vector<int> s = heights;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        vector<int> ans(m);
        auto j = n - 1;
        BinaryIndexedTree tree(n);
        int l;
        int r;
        int k;
        for (auto i : idx) {
            l = queries[i][0];
            r = queries[i][1];
            while (j > r) {
                k = s.end() - lower_bound(s.begin(), s.end(), heights[j]) + 1;
                tree.update(k, j);
                --j;
            }
            if (l == r || heights[l] < heights[r]) {
                ans[i] = r;
            } else {
                k = s.end() - lower_bound(s.begin(), s.end(), heights[l]);
                ans[i] = tree.query(k);
            }
        }
        return ans;
    }
};
