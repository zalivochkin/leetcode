
import java.util.*;

class Solution {
    public int[] minOperations(String boxes) {
        var n = boxes.length();
        int[] res = new int[n];
        int cnt = 0;
        for (var i = 1; i < n; ++i) {
            cnt += boxes.charAt(i - 1) == '1' ? 1 : 0;
            res[i] = res[i - 1] + cnt;
        }
        cnt = 0;
        int summ = 0;
        for (int i = n - 2; i >= 0; --i) {
            cnt += boxes.charAt(i + 1) == '1' ? 1 : 0;
            summ += cnt;
            res[i] += summ;
        }
        return res;
    }
}
