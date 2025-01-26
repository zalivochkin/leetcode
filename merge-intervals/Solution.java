
import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(v -> v[0]));
        List<int[]> res = new ArrayList<>();
        res.add(intervals[0].clone());
        for (var i = 1; i < intervals.length; ++i) {
            int n = res.size();
            if (intervals[i][0] <= res.get(n - 1)[1]) {
                res.get(n - 1)[1] = Math.max(res.get(n - 1)[1], intervals[i][1]);
            } else {
                res.add(intervals[i].clone());
            }
        }
        return res.toArray(new int[res.size()][2]);
    }
}
