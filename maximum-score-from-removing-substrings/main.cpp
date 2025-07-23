
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a = 'a';
        char b = 'b';
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        int ans = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (const auto ch : s) {
            if (ch == a) {
                cnt1++;
            } else if (ch == b) {
                if (cnt1) {
                    ans += x;
                    cnt1--;
                } else {
                    cnt2++;
                }
            } else {
                ans += min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }
        ans += min(cnt1, cnt2) * y;
        return ans;
    }
};
