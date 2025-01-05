
import java.util.*;

class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        var n = s.length();
        var prefSum = new int[n + 1];
        for (var shift : shifts) {
            if (shift[2] == 0) {
                shift[2]--;
            }
            prefSum[shift[0]] += shift[2];
            prefSum[shift[1] + 1] -= shift[2];
        }
        for (var i = 1; i <= n; ++i) {
            prefSum[i] += prefSum[i - 1];
        }
        StringBuilder sb = new StringBuilder();
        for (var i = 0; i < n; ++i) {
            sb.append((char) ('a' + (s.charAt(i) - 'a' + prefSum[i] % 26 + 26) % 26));
        }
        return sb.toString();
    }
}
