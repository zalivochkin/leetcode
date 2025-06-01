
class Solution {
public:
    long long comb(int n) {
        return 1LL * n * (n - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        if (n > 3 * limit) {
            return 0;
        }
        long long ans = comb(n + 2);
        if (n > limit) {
            ans -= 3 * comb(n - limit + 1);
        }
        if (n - 2 >= 2 * limit) {
            ans += 3 * comb(n - 2 * limit);
        }
        return ans;
    }
};
