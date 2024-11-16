
class Solution {
public:
    string makeFancyString(string s) {
        string res = s;
        char last_ch = s[0];
        int cnt = 0;
        int j = 0;
        for (const auto ch : s) {
            if (ch == last_ch) {
                ++cnt;
                if (cnt < 3) {
                    res[j++] = ch;
                }
            } else {
                last_ch = ch;
                cnt = 1;
                res[j++] = ch;
            }
        }
        res.resize(j);
        return res;
    }
};
