
class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch] += 1;
        }
        int res = 0;
        for (const auto &itm : mp) {
            if (itm.second > 2) {
                res += itm.second % 2 == 0 ? 2 : 1;
            } else {
                res += itm.second;
            }
        }
        return res;
    }
};
