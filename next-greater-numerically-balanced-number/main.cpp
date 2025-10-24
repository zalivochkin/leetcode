
class Solution {
public:
    int nextBeautifulNumber(int n) {
        int x = n + 1;
        while (true) {
            int cnt[10]{};
            for (int y = x; y > 0; y /= 10) {
                cnt[y % 10] += 1;
            }
            bool ok = true;
            for (int y = x; y > 0; y /= 10) {
                if (y % 10 != cnt[y % 10]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return x;
            }
            ++x;
        }
    }
};
