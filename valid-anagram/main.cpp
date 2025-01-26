
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> mp;
        for (auto ch : s) {
            mp[ch] += 1;
        }
        for (auto ch : t) {
            if (!mp.contains(ch)) {
                return false;
            }
            mp[ch] -= 1;
            if (mp[ch] == 0) {
                mp.erase(ch);
            }
        }
        return mp.empty();
    }
};
