
class Solution {
public:
    string sortVowels(string s) {
        vector<int> vs;
        for (auto ch : s) {
            auto d = tolower(ch);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                vs.push_back(ch);
            }
        }
        ranges::sort(vs);
        const auto n = s.size();
        for (int i = 0, j = 0; i < n; ++i) {
            auto d = tolower(s[i]);
            if (d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') {
                s[i] = vs[j];
                ++j;
            }
        }
        return s;
    }
};
