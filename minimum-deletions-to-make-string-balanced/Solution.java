
class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int ans = 0;
        int b = 0;
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == 'b') {
                ++b;
            } else {
                ans = Math.min(ans + 1, b);
            }
        }
        return ans;
    }
}
