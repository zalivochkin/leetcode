
class Solution {
    public int numberOfBeams(String[] bank) {
        int ans = 0;
        int pre = 0;
        for (final var row : bank) {
            int cur = 0;
            for (var i = 0; i < row.length(); ++i) {
                cur += row.charAt(i) - '0';
            }
            if (cur > 0) {
                ans += pre * cur;
                pre = cur;
            }
        }
        return ans;
    }
}
