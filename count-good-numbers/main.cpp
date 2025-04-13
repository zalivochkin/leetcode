
class Solution {
public:
    int countGoodNumbers(long long n) {
        const int mod = static_cast<int>(1e9) + 7;
        return (int) (mod_pow(5, (n + 1) / 2, mod) * mod_pow(4, n / 2, mod) % mod);
    }
    long long mod_pow(long long num, long long pwr, const int mod) {
        long long res = 1;
        while (pwr != 0) {
            if ((pwr & 1) == 1) {
                res = res * num % mod;
            }
            num = num * num % mod;
            pwr /= 2;
        }
        return res;
    }
};
