
import java.util.*;

class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int Max = 0;
        int res = 0;
        for (var i = 0; i < values.length; ++i) {
            res = Math.max(res, values[i] - i + Max);
            Max = Math.max(Max, values[i] + i);
        }
        return res;
    }
}
