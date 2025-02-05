
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        const auto n = s1.size();
        int cnt = 0;
        char ch1 = 0;
        char ch2 = 0;
        for (auto i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                ++cnt;
                if (cnt > 2 || (cnt == 2 && (s1[i] != ch2 || s2[i] != ch1))) {
                    return false;
                }
                ch1 = s1[i];
                ch2 = s2[i];
            }
        }
        return cnt != 1;
    }
};
