
class Solution {
    public int findClosest(int x, int y, int z) {
        final var distx = Math.abs(z - x);
        final var disty = Math.abs(z - y);
        if (distx == disty) {
            return 0;
        } else if (distx < disty) {
            return 1;
        }
        return 2;
    }
}
