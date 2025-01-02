
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const auto n = words.size();
        const auto m = queries.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<int> pref_sum(n + 1);
        pref_sum[0] = 0;
        for (auto i = 0; i < n; ++i) {
            pref_sum[i + 1] = (vowels.contains(words[i][0]) && vowels.contains(words[i].back())) ? pref_sum[i] + 1 : pref_sum[i];
        }
        vector<int> res(m);
        for (auto i = 0; i < m; ++i) {
            res[i] = pref_sum[queries[i][1] + 1] - pref_sum[queries[i][0]];
        }
        return res;
    }
};
