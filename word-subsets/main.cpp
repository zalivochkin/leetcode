
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int max_cnt[26] = {0};
        int tmp_cnt[26];
        for (const auto &word : words2) {
            memset(tmp_cnt, 0, sizeof tmp_cnt);
            for (auto &ch : word) {
                tmp_cnt[ch - 'a']++;
            }
            for (auto i = 0; i < 26; ++i) {
                max_cnt[i] = max(max_cnt[i], tmp_cnt[i]);
            }
        }
        vector<string> res;
        bool is_unique;
        for (const auto &word : words1) {
            memset(tmp_cnt, 0, sizeof tmp_cnt);
            for (auto &ch : word) {
                tmp_cnt[ch - 'a']++;
            }
            is_unique = true;
            for (auto i = 0; i < 26; ++i) {
                if (max_cnt[i] > tmp_cnt[i]) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                res.emplace_back(word);
            }
        }
        return res;
    }
};
