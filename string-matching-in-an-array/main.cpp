
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        const auto n = words.size();
        vector<string> res;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (i != j && words[j].size() >= words[i].size() && words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};
