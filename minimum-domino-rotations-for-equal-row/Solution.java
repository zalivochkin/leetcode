
class Solution {
    private int n;
    private int[] tops;
    private int[] bottoms;

    public int minDominoRotations(int[] tops, int[] bottoms) {
        n = tops.length;
        this.tops = tops;
        this.bottoms = bottoms;
        int ans = Math.min(fn(tops[0]), fn(bottoms[0]));
        return ans > n ? -1 : ans;
    }

    private int fn(int x) {
        int cnt1 = 0;
        int cnt2 = 0;
        for (var i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x) {
                return n + 1;
            }
            if (tops[i] == x) {
                ++cnt1;
            }
            if (bottoms[i] == x) {
                ++cnt2;
            }
        }
        return n - Math.max(cnt1, cnt2);
    }
}
