
class Solution {
    public int countGoodNumbers(long n) {
        int mod = (int) 1e9 + 7;
        return (int) (modPow(5, (n + 1) / 2, mod) * modPow(4, n / 2, mod) % mod);
    }
    long modPow(long num, long pwr, int mod) {
        long res = 1;
        while (pwr != 0) {
            if ((pwr & 1) == 1) {
                res = res * num % mod;
            }
            num = num * num % mod;
            pwr /= 2;
        }
        return res;
    }
}
