
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        const auto n = s.size();
        const auto m = spaces.size();
        string res(n + m, ' ');
        auto j = 0;
        for (auto i = 0; i < n; ++i) {
            if (j < m && i == spaces[j]) {
                ++j;
            }
            res[i + j] = s[i];
        }
        return res;
    }
};
