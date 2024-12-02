
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        const auto n = sentence.size();
        const auto m = searchWord.size();
        int res = 1;
        int j;
        for (auto i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
		if (i + j == n) {
                    return -1;
                }
                if (sentence[i + j] == ' ' || sentence[i + j] != searchWord[j]) {
                    i += j;
                    break;
                }
            }
            if (j == m) {
                return res;
            }
            while (i < n && sentence[i] != ' ') {
                ++i;
            }
            ++res;
        }
        return -1;
    }
};
