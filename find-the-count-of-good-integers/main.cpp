
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<long long> fac(n + 1, 1);
        for (auto i = 1; i <= n; ++i) {
            fac[i] = fac[i - 1] * i;
        }

        long long ans = 0;
        unordered_set<string> vis;
        int base = static_cast<int>(pow(10, (n - 1) / 2));
        vector<int> cnts(10);
        for (auto i = base; i < base * 10; ++i) {
            string s = to_string(i);
            string rev = s;
            ranges::reverse(rev);
            s += rev.substr(n % 2);
            if (stoll(s) % k) {
                continue;
            }
            string t = s;
            ranges::sort(t);
            if (vis.contains(t)) {
                continue;
            }
            vis.insert(t);
            ranges::fill(cnts, 0);
            for (auto ch : t) {
                cnts[ch - '0']++;
            }
            long long res = (n - cnts[0]) * fac[n - 1];
            for (auto cnt : cnts) {
                res /= fac[cnt];
            }
            ans += res;
        }
        return ans;
    }
};
