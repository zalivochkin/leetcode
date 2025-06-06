
class Solution {
public:
    string robotWithString(string s) {
        int cnt[26] = {0};
        for (auto c : s) {
            cnt[c - 'a'] += 1;
        }
        char mi = 'a';
        string stk;
        string ans;
        for (auto c : s) {
            --cnt[c - 'a'];
            while (mi < 'z' && cnt[mi - 'a'] == 0) {
                ++mi;
            }
            stk += c;
            while (!stk.empty() && stk.back() <= mi) {
                ans += stk.back();
                stk.pop_back();
            }
        }
        return ans;
    }
};
