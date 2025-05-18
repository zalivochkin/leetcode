
class Solution {
public:
    bool f1(int m, int x) {
        int last = -1;
        for (int i = 0; i < m; ++i) {
            if (x % 3 == last) {
                return false;
            }
            last = x % 3;
            x /= 3;
        }
        return true;
    }

    bool f2(int m, int x, int y) {
        for (int i = 0; i < m; ++i) {
            if (x % 3 == y % 3) {
                return false;
            }
            x /= 3;
            y /= 3;
        }
        return true;
    }

    int colorTheGrid(int m, int n) {
        const int mod = 1e9 + 7;
        int mx = pow(3, m);
        unordered_set<int> valid;
        vector<int> f(mx);
        for (int i = 0; i < mx; ++i) {
            if (f1(m, i)) {
                valid.insert(i);
                f[i] = 1;
            }
        }
        unordered_map<int, vector<int>> d;
        for (int i: valid) {
            for (int j: valid) {
                if (f2(m, i, j)) {
                    d[i].push_back(j);
                }
            }
        }
        vector<int> g(mx);
        for (int k = 1; k < n; ++k) {
            ranges::fill(g, 0);
            for (int i: valid) {
                for (int j: d[i]) {
                    g[i] = (g[i] + f[j]) % mod;
                }
            }
            swap(f, g);
        }
        int ans = 0;
        for (int x: f) {
            ans = (ans + x) % mod;
        }
        return ans;
    }
};
