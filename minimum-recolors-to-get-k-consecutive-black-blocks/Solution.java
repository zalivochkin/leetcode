
class Solution {
    public int minimumRecolors(String blocks, int k) {
        final var n = blocks.length();
        int cnt = 0;
        for (var i = 0; i < k; i++) {
            if (blocks.charAt(i) == 'W') {
                ++cnt;
            }
        }
        int minCnt = cnt;
        for (var i = k; i < n; i++) {
            if (blocks.charAt(i) == 'W') {
                ++cnt;
            }
            if (blocks.charAt(i - k) == 'W') {
                --cnt;
            }
            minCnt = Math.min(minCnt, cnt);
        }
        return minCnt;
    }
}
