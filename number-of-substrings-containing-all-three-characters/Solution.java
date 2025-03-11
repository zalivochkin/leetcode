
class Solution {
    public int numberOfSubstrings(String s) {
        final var n = s.length();
        int[] d = new int[] {-1, -1, -1};
        int ans = 0;
        for (var i = 0; i < n; ++i) {
            d[s.charAt(i) - 'a'] = i;
            ans += Math.min(d[0], Math.min(d[1], d[2])) + 1;
        }
        return ans;
    }
}
