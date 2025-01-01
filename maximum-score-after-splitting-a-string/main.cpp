
class Solution {
public:
    int maxScore(string s) {
        const auto n = s.size();
        int lft = 0;
        int rght = count(s.begin(), s.end(), '1');
        int res = 0;
        for (auto i = 0; i < n - 1; ++i) {
            lft += (s[i] - '0') ^ 1;
            rght -= s[i] - '0';
            res = max(res, lft + rght);
        }
        return res;
    }
};
