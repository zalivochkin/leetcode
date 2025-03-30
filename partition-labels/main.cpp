
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        const auto n = s.size();
        for (auto i = 0; i < n; ++i) {
            last[s[i]] = i;
        }
        vector<int> ans;
        int mx = 0;
        int end = 0;
        for (auto start = 0; start < n; ++start) {
            mx = max(mx, last[s[start]]);
            if (mx == start) {
                ans.push_back(start - end + 1);
                end = start + 1;
            }
        }
        return ans;
    }
};
