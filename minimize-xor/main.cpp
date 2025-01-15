
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        auto cnt1 = __builtin_popcount(num1);
        auto cnt2 = __builtin_popcount(num2);
        while (cnt1 > cnt2) {
            num1 &= (num1 - 1);
            --cnt1;
        }
        while (cnt1 < cnt2) {
            num1 |= (num1 + 1);
            ++cnt1;
        }
        return num1;
    }
};
