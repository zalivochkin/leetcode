
class Solution {
    public int makeTheIntegerZero(int num1, int num2) {
        long k = 1;
        while (true) {
            long x = num1 - k * num2;
            if (x < 0) {
                break;
            }
            if (Long.bitCount(x) <= k && k <= x) {
                return (int) k;
            }
            ++k;
        }
        return -1;
    }
}
