
class Solution {
    public int maximumGain(String s, int x, int y) {
        char a = 'a';
        char b = 'b';
        if (x < y) {
            int t = x;
            x = y;
            y = t;
            char c = a;
            a = b;
            b = c;
        }
        int ans = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        final var n = s.length();
        for (var i = 0; i < n; ++i) {
            char ch = s.charAt(i);
            if (ch == a) {
                cnt1++;
            } else if (ch == b) {
                if (cnt1 > 0) {
                    ans += x;
                    cnt1--;
                } else {
                    cnt2++;
                }
            } else {
                ans += Math.min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }
        ans += Math.min(cnt1, cnt2) * y;
        return ans;
    }
}
