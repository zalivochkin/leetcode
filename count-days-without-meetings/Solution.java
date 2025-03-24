
import java.util.*;

class Solution {
    public int countDays(int days, int[][] meetings) {
        final var n = meetings.length;
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));
        int res = meetings[0][0] - 1;
        for (var i = 1; i < n; ++i) {
            if (meetings[i][0] <= meetings[i - 1][1]) {
                meetings[i][1] = Math.max(meetings[i][1], meetings[i - 1][1]);
            } else {
                res += meetings[i][0] - meetings[i - 1][1] - 1;
            }
        }
        res += days - meetings[n - 1][1];
        return res;
    }
}
