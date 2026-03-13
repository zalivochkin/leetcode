
class Solution {
    private int mountainHeight;
    private int[] workerTimes;

    public long minNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        this.mountainHeight = mountainHeight;
        this.workerTimes = workerTimes;
        long l = 1;
        long r = Long.MAX_VALUE;
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private boolean check(long t) {
        long h = 0;
        for (int wt : workerTimes) {
            h += (long) (Math.sqrt(t * 2.0 / wt + 0.25) - 0.5);
        }
        return h >= mountainHeight;
    }
}
