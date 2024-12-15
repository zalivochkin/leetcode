
import java.util.*;

class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<double[]> pq = new PriorityQueue<>((d1, d2) -> Double.compare(d2[0], d1[0]));
        for (var clas : classes) {
            var rat = (double) clas[0] / (double) clas[1];
            var next_rat = (double) (clas[0] + 1) / (double) (clas[1] + 1);
            pq.add(new double[]{next_rat - rat, clas[0], clas[1]});
        }
        for (var i = 0; i < extraStudents; ++i) {
            var cl = pq.poll();
            cl[1] += 1;
            cl[2] += 1;
            cl[0] = (cl[1] + 1.0) / (cl[2] + 1.0) - cl[1] / cl[2];
            pq.add(cl);
        }
        double ans = 0;
        while (!pq.isEmpty()) {
            var cl = pq.poll();
            ans += cl[1] / cl[2];
        }
        return ans / (double) classes.length;
    }
}
