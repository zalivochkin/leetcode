
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const auto n = s.size();
        const auto m = words.size();
        const auto k = words[0].size();
        unordered_map<string, int> cnts;
        for (const auto &word : words) {
            cnts[word] += 1;
        }
        vector<int> res;
        for (auto i = 0; i < k; ++i) {
            int cnt = 0;
            unordered_map<string, int> tmp;
            for (auto j = i; j <= n; j += k) {
                if (j - i >= m * k) {
                    const auto ts = s.substr(j - m * k, k);
                    tmp[ts] -= 1;
                    if (cnts[ts] > tmp[ts]) {
                        cnt -= 1;
                    }
                }
                auto ts = s.substr(j, k);
                tmp[ts] += 1;
                if (cnts[ts] >= tmp[ts]) {
                    cnt += 1;
                }
                if (cnt == m) {
                    res.push_back(j - (m - 1) * k);
                }
            }
        }
        return res;
    }
};
