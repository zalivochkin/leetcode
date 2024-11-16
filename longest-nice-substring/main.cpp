
class Solution {
public:
    inline bool isNice(const string s, const int start, const int end, const int delta) const {
        unordered_set<char> uppers;
        unordered_set<char> lowers;
        for (auto i = start; i <= end; ++i) {
            auto ch = s[i];
            if (ch < 'a') {
                uppers.insert(ch);
            } else {
                lowers.insert(ch - delta);
            }
        }
        if (uppers.size() != lowers.size()) {
            return false;
        }
        for (auto ch : uppers) {
            if (!lowers.contains(ch)) {
                return false;
            }
        }
        return true;
    }

    string longestNiceSubstring(string s) {
        if (s.size() < 2) {
            return "";
        }
        auto n = s.size();
        unordered_set<char> us;
        for (auto ch : s) {
            us.insert(ch);
        }
        for (auto i = 0; i < n; ++i) {
            if (us.contains(tolower(s[i])) && us.contains(toupper(s[i]))) {
                continue;
            }
            string lft_s = longestNiceSubstring(s.substr(0, i));
            string rght_s = longestNiceSubstring(s.substr(i + 1));
            return lft_s.size() >= rght_s.size() ? lft_s : rght_s;
        }
        return s;
    }
};
