
class Solution {
public:
    int dfs(unordered_map<long long, int> &f, const string &s, int k, int i, int cur, int t) {
        int n = s.size();
        if (i >= n) {
            return 1;
        }
        long long key = (long long) i << 32 | cur << 1 | t;
        if (f.count(key)) {
            return f[key];
        }
        int v = 1 << (s[i] - 'a');
        int nxt = cur | v;
        int ans = __builtin_popcount(nxt) > k ? dfs(f, s, k, i + 1, v, t) + 1 : dfs(f, s, k, i + 1, nxt, t);
        if (t) {
            for (int j = 0; j < 26; ++j) {
                nxt = cur | (1 << j);
                if (__builtin_popcount(nxt) > k) {
                    ans = max(ans, dfs(f, s, k, i + 1, 1 << j, 0) + 1);
                } else {
                    ans = max(ans, dfs(f, s, k, i + 1, nxt, 0));
                }
            }
        }
        return f[key] = ans;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> f;
        return dfs(f, s, k, 0, 0, 1);
    }
};
