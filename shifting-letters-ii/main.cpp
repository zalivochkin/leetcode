
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const auto n = s.size();
        vector<int> pref_sum(n + 1);
        for (auto &shift : shifts) {
            if (shift[2] == 0) {
                shift[2]--;
            }
            pref_sum[shift[0]] += shift[2];
            pref_sum[shift[1] + 1] -= shift[2];
        }
        for (auto i = 1; i <= n; ++i) {
            pref_sum[i] += pref_sum[i - 1];
        }
        string res;
        for (auto i = 0; i < n; ++i) {
            res += 'a' + (s[i] - 'a' + pref_sum[i] % 26 + 26) % 26;
        }
        return res;
    }
};
