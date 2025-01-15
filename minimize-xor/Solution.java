
import java.util.*;

class Solution {
    public int minimizeXor(int num1, int num2) {
        var cnt1 = Integer.bitCount(num1);
        var cnt2 = Integer.bitCount(num2);
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
}
