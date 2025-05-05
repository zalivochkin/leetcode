
class Solution {
public:
    int numTilings(int n) {
        static const int mod = 1e9 + 7;
        vector<long> f{1, 0, 0, 0};
        vector<long> g(4);
        for (auto i = 1; i <= n; ++i) {
            ranges::fill(g, 0);
            g[0] = (f[0] + f[1] + f[2] + f[3]) % mod;
            g[1] = (f[2] + f[3]) % mod;
            g[2] = (f[1] + f[3]) % mod;
            g[3] = f[0];
            swap(f, g);
        }
        return f[0];
    }
};
