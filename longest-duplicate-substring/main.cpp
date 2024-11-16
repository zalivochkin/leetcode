
class Solution {
public:
    bool rk(const string &s, int len, size_t power, int x, string &res) {
        int n = s.size();
        unordered_set<size_t> seen;
        size_t hash = 0;
        for (int i = 0; i < len; i++) {
            hash = hash * x + s[i];
        }
        seen.insert(hash);
        for (int i = len; i < n; i++) {
            hash = hash - power * s[i - len];
            hash = hash * x + s[i];
            if (seen.find(hash) != seen.end()) {
                res = s.substr(i - len + 1, len);
                return true;
            }
            seen.insert(hash);
        }
        return false;
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        int x = 131;
        vector<size_t> power(n, 1);
        for (int i = 1; i < n; i++){
            power[i] = power[i - 1] * x;
        }
        int len_l = 0;
        int len_r = n - 1;
        string res, tmp;
        while (len_l < len_r) {
            int len_mid = len_l + (len_r - len_l) / 2;
            if (!rk(s, len_mid + 1, power[len_mid], x, tmp)) {
                len_r = len_mid;
            } else {
                len_l = len_mid + 1;
                res = tmp;
            }
        }
        if (len_l == 0) {
            return "";
        }
        return res;
    }
};
