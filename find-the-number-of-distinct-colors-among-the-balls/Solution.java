
import java.util.*;

class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        final var n = queries.length;
        Map<Integer, Integer> colors = new HashMap<>();
        Map<Integer, Integer> colorsCnts = new HashMap<>();
        int[] res = new int[n];
        for (var i = 0; i < n; ++i) {
            final var ballNum = queries[i][0];
            final var ballColor = queries[i][1];
            colorsCnts.merge(ballColor, 1, Integer::sum);
            if (colors.containsKey(ballNum)) {
                colorsCnts.merge(colors.get(ballNum), -1, Integer::sum);
                if (colorsCnts.get(colors.get(ballNum)) == 0) {
                    colorsCnts.remove(colors.get(ballNum));
                }
            }
            colors.put(ballNum, ballColor);
            res[i] = colorsCnts.size();
        }
        return res;
    }
}
