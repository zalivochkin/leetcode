
class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        long x = 0;
        long mi = 0;
        long mx = 0;
        for (var d : differences) {
            x += d;
            mi = Math.min(mi, x);
            mx = Math.max(mx, x);
        }
        return (int) Math.max(upper - lower - (mx - mi) + 1, 0);
    }
}
