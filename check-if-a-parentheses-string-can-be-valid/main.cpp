
class Solution {
public:
    bool canBeValid(string s, string locked) {
        const auto n = s.size();
        if (n & 1) {
            return false;
        }
        int cntr = 0;
        for (auto i = 0; i < n; ++i) {
            if (s[i] == '(' || locked[i] == '0') {
                ++cntr;
            } else if (cntr > 0) {
                --cntr;
            } else {
                return false;
            }
        }
        cntr = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')' || locked[i] == '0') {
                ++cntr;
            } else if (cntr > 0) {
                --cntr;
            } else {
                return false;
            }
        }
        return true;
    }
};
