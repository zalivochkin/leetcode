
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        auto n = text.size();
        vector<int> broken_letters('z' + 1, 0);
        for (auto ch : brokenLetters) {
            broken_letters[ch] = 1;
        }
        int res = 0;
        for (auto i = 0; i < n; ++i) {
            if (text[i] == ' ' || (i == n - 1 && broken_letters[text[i]] == 0)) {
                ++res;
            } else {
                if (broken_letters[text[i]] == 1) {
                    while (i < n && text[i] != ' ') {
                        ++i;
                    }
                }
            }
        }
        return res;
    }
};
