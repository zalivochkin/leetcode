
class Solution {
public:
    int maximumLength(string s) {
        const auto n = s.size();
        auto res = -1;
        unordered_map<string, int> freq;
        for (auto len = 1; len <= n; ++len) {
            freq.clear();
            for (auto i = 0; i <= n - len; ++i) {
                string sub = s.substr(i, len);
                bool is_special = true;
                for (int j = 1; j < len; ++j) {
                    if (sub[j] != sub[0]) {
                        is_special = false;
                        break;
                    }
                }
                if (is_special) {
                    freq[sub]++;
                    if (freq[sub] >= 3) {
                        res = max(res, len);
                    }
                }
            }
        }
        return res;
    }
};
