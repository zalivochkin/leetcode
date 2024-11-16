
class Solution {
public:
    inline long long countNumbersWithPrefix(int prefix, int n) {
        long long firstNumber = prefix;
        long long nextNumber = prefix + 1;
        long long count = 0;
        while (firstNumber <= n) {
            count += min(n + 1LL, nextNumber) - firstNumber;
            firstNumber *= 10;
            nextNumber *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        int prefix = 1;
        --k;  // Decrement k to handle zero-based indexing
        long long count;
        while (k > 0) {
            count = countNumbersWithPrefix(prefix, n);
            if (k >= count) {
                ++prefix;  // Move to the next prefix
                k -= count;
            } else {
                prefix *= 10;  // Go deeper in the current prefix
                --k;
            }
        }
        return prefix;
    }
};
