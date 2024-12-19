
import java.util.*;

class Solution {
    public int mySqrt(int x) {
        long leftY = 0;
        long rightY = x / 2;
        while (rightY - leftY > 1) {
            long midY = leftY + (rightY - leftY) / 2;
            if (midY * midY > x) {
                rightY = midY - 1;
            } else {
                leftY = midY;
            }
        }
        if ((leftY + 1) * (leftY + 1) <= x) {
            return (int) leftY + 1;
        }
        return (int) leftY;
    }
}
