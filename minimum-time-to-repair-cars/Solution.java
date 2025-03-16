
class Solution {
    public long repairCars(int[] ranks, int cars) {
        long lft = 0;
        long rght = (long) ranks[0] * cars * cars;
        while (lft < rght) {
            long mid = lft + (rght - lft) / 2;
            long cnt = 0;
            for (var rank : ranks) {
                cnt += (long) Math.sqrt((double) mid / rank);
            }
            if (cnt >= cars) {
                rght = mid;
            } else {
                lft = mid + 1;
            }
        }
        return lft;
    }
}
