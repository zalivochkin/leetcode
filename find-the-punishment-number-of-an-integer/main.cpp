
class Solution {
public:
    bool check(const string& s, int i, int x) {
        const auto n = s.size();
        if (i >= n) {
            return x == 0;
        }
        int y = 0;
        for (auto j = i; j < n; ++j) {
            y = y * 10 + s[j] - '0';
            if (y > x) {
                break;
            }
            if (check(s, j + 1, x - y)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (auto i = 1; i <= n; ++i) {
            int x = i * i;
            string s = to_string(x);
            if (check(s, 0, i)) {
                ans += x;
            }
        }
        return ans;
    }
};
