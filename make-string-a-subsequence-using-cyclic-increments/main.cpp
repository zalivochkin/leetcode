
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        const auto n = str1.size();
        const auto m = str2.size();
        if (n < m) {
            return false;
        }
        int j = 0;
        for (int i = 0; i < n && j < m; ++i) {
            if (str1[i] == str2[j] || str1[i] + 1 == str2[j] || (str1[i] == 'z' && str2[j] == 'a')) {
                ++j;
            }
        }
        return j == m;
    }
};
