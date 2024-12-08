import java.util.*;

public class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (e1, e2) -> {
            if (e1[0] == e2[0]) {
                return e1[1] < e2[1] ? -1 : 1;
            }
            return e1[0] < e2[0] ? -1 : 1;
        });
        var n = events.length;
        int[] maxs = new int[n + 1];
        for (int i = n - 1; i >= 0; --i) {
            maxs[i] = Math.max(maxs[i + 1], events[i][2]);
        }
        int res = 0;
        int lft, rght, mid;
        for (var event : events) {
            lft = 0;
            rght = n;
            while (lft < rght) {
                mid = lft + (rght - lft) / 2;
                if (events[mid][0] > event[1]) {
                    rght = mid;
                } else {
                    lft = mid + 1;
                }
            }
            if (lft < n) {
                event[2] += maxs[lft];
            }
            res = Math.max(res, event[2]);
        }
        return res;
    }
}
