
class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int ans = 0;
        int mx = 0;
        for (var dimension : dimensions) {
            int length = dimension[0];
            int width = dimension[1];
            int t = length * length + width * width;
            if (mx < t) {
                mx = t;
                ans = length * width;
            } else if (mx == t) {
                ans = Math.max(ans, length * width);
            }
        }
        return ans;
    }
}
