
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> smbs = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans = {""};
        for (const auto &ch : digits) {
            string s = smbs[ch - '2'];
            vector<string> t;
            for (const auto &s2 : ans) {
                for (const auto &s3 : s) {
                    t.push_back(s2 + s3);
                }
            }
            swap(ans, t);
        }
        return ans;
    }
};
