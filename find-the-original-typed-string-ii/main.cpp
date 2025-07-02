
class Solution {
public:
    int possibleStringCount(string word, int k) {
        const vector<int> groups = getConsecutiveLetters(word);
        const int total_combs = accumulate(groups.begin(), groups.end(), 1L, [](long acc, int group) { return acc * group % MOD; });
        const auto n = groups.size(); 
        if (k <= n) {
            return total_combs;
        }
        vector<int> dp(k);
        dp[0] = 1;
        for (auto i = 0; i < n; ++i) {
            vector<int> new_dp(k);
            int window_sum = 0;
            int group = groups[i];
            for (auto j = i; j < k; ++j) {
                new_dp[j] = (new_dp[j] + window_sum) % MOD;
                window_sum = (window_sum + dp[j]) % MOD;
                if (j >= group) {
                    window_sum = (window_sum - dp[j - group] + MOD) % MOD;
                }
            }
            swap(dp, new_dp);
        }
        const int invalid_combs = accumulate(dp.begin(), dp.end(), 0, [](int acc, int count) { return (acc + count) % MOD; });
        return (total_combs - invalid_combs + MOD) % MOD;
    }

private:
    static constexpr int MOD = 1e9 + 7;
    static vector<int> getConsecutiveLetters(const string& word) {
        vector<int> groups;
        int group = 1;
        const auto n = word.length();
        for (auto i = 1; i < n; ++i)
            if (word[i] == word[i - 1]) {
                ++group;
            } else {
                groups.push_back(group);
                group = 1;
            }
        groups.push_back(group);
        return groups;
    }
};
