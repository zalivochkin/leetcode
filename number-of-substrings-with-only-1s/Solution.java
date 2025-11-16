
class Solution {
    public int numSub(String s) {
        final int mod = (int) 1e9 + 7;
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '1') {
                ++cnt;
            } else {
                cnt = 0;
            }
            ans = (ans + cnt) % mod;
        }
        return ans;
    }
}
