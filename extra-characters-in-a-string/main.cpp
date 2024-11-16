
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const auto n = s.size() + 1;
        std::vector<int> dp(n);
        dp[0] = 0;
        auto m = n;
        for (auto i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (const auto &word: dictionary) {
                m = word.size();
                if (i >= m) {
                    if (s.substr(i - m, m) == word) {
                        dp[i] = min(dp[i], dp[i - m]);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
