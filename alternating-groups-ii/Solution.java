﻿
class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        final var n = colors.length;
        int ans = 0;
        int cnt = 0;
        for (var i = 0; i < n * 2; ++i) {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            if (i >= n && cnt >= k) {
                ++ans;
            }
        }
        return ans;
    }
}
