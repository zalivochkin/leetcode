
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        vector<int> cnts(26, 0);
        for (const auto ch : s) {
            cnts[ch - 'a'] += 1;
        }
        int odd_counts = 0;
        for (const auto cnt : cnts) {
            odd_counts += cnt & 1;
        }
        return odd_counts <= k;
    }
};
