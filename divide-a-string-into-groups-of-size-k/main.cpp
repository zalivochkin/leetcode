
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        auto n = s.size();
        if (n % k) {
            s += string(k - n % k, fill);
        }
        vector<string> ans;
        n = s.size() / k;
        for (int i = 0; i < n; ++i) {
            ans.push_back(s.substr(i * k, k));
        }
        return ans;
    }
};
