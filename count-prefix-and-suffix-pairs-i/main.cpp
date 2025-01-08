
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        const auto n = words.size();
        int res = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j < n; ++j) {
                if (words[j].find(words[i]) == 0 && words[j].rfind(words[i]) == words[j].size() - words[i].size()) {
                    ++res;
                }
            }
        }
        return res;
    }
};
