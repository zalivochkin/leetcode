
import java.util.*;

class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<List<Integer>> mergedIntervals = new ArrayList<>();
        mergedIntervals.add(new ArrayList<>(List.of(newInterval[0], newInterval[1])));
        for (var i = 0; i < intervals.length; ++i) {
            mergedIntervals.add(new ArrayList<>(List.of(intervals[i][0], intervals[i][1])));
        }
        mergedIntervals.sort((a1, a2) -> a1.get(0) - a2.get(0));
        for (var i = 1; i < mergedIntervals.size(); ++i) {
            if (mergedIntervals.get(i).get(0) >= mergedIntervals.get(i - 1).get(0) && mergedIntervals.get(i).get(0) <= mergedIntervals.get(i - 1).get(1)) {
                mergedIntervals.get(i).set(0, Math.min(mergedIntervals.get(i - 1).get(0), mergedIntervals.get(i).get(0)));
                mergedIntervals.get(i).set(1, Math.max(mergedIntervals.get(i - 1).get(1), mergedIntervals.get(i).get(1)));
                mergedIntervals.remove(i - 1);
                --i;
            }
        }
        int[][] res = new int[mergedIntervals.size()][2];
        for (var i = 0; i < mergedIntervals.size(); ++i) {
            res[i][0] = mergedIntervals.get(i).get(0);
            res[i][1] = mergedIntervals.get(i).get(1);
        }
        return res;
    }
}
