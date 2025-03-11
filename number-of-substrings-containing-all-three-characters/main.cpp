
class Solution {
public:
    int numberOfSubstrings(string s) {
        const auto n = s.size();
        vector<int> d(3, -1);
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            d[s[i] - 'a'] = i;
            ans += min(d[0], min(d[1], d[2])) + 1;
        }
        return ans;
    }
};
