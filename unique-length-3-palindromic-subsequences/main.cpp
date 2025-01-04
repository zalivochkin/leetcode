
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        int lft;
        int rght;
        unordered_set<char> cs;
        for (auto ch = 'a'; ch <= 'z'; ++ch) {
            lft = s.find_first_of(ch);
            rght = s.find_last_of(ch);
            cs.clear();
            for (auto i = lft + 1; i < rght; ++i) {
                cs.insert(s[i]);
            }
            res += cs.size();
        }
        return res;
    }
};
