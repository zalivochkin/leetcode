
class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const auto [fact, invFact] = getFactAndInvFact(n);
        return m * modPow(m - 1, n - k - 1) % k_mod * nCk(n - 1, k, fact, invFact) % k_mod;
    }

private:
    static constexpr int k_mod = 1e9 + 7;

    long modPow(long x, long n) {
        if (n == 0) {
            return 1;
        }
        if (n % 2 == 1) {
            return x * modPow(x % k_mod, (n - 1)) % k_mod;
        }
        return modPow(x * x % k_mod, (n / 2)) % k_mod;
    }

    static pair<vector<long>, vector<long>> getFactAndInvFact(int n) {
        vector<long> fact(n + 1);
        vector<long> inv_fact(n + 1);
        vector<long> inv(n + 1);
        fact[0] = inv_fact[0] = 1;
        inv[0] = inv[1] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i >= 2) {
                inv[i] = k_mod - k_mod / i * inv[k_mod % i] % k_mod;
            }
            fact[i] = fact[i - 1] * i % k_mod;
            inv_fact[i] = inv_fact[i - 1] * inv[i] % k_mod;
        }
        return {fact, inv_fact};
    }

    static int nCk(int n, int k, const vector<long>& fact, const vector<long>& invFact) {
        return fact[n] * invFact[k] % k_mod * invFact[n - k] % k_mod;
    }
};
