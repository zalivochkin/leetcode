
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long k = 1;
        while (true) {
            long long x = num1 - k * num2;
            if (x < 0) {
                break;
            }
            if (__builtin_popcountll(x) <= k && k <= x) {
                return k;
            }
            ++k;
        }
        return -1;
    }
};
