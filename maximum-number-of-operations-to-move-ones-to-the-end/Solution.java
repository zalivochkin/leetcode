
class Solution {
    public int maxOperations(String s) {
        int ans = 0;
        int cnt = 0;
        final var n = s.length();
        for (var i = 0; i < n; ++i) {
            if (s.charAt(i) == '1') {
                ++cnt;
            } else if (i > 0 && s.charAt(i - 1) == '1') {
                ans += cnt;
            }
        }
        return ans;
    }
}
