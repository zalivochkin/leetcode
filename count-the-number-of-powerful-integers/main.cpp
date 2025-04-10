
class Solution {
public:
    long long dfs(const string &s, int limit, const string &tmp_str, vector<long long> &dp, int pos, bool lim) {
        if (tmp_str.size() < s.size()) {
            return 0;
        }
        if (!lim && dp[pos] != -1) {
            return dp[pos];
        }
        if (tmp_str.size() - pos == s.size()) {
            return lim ? s <= tmp_str.substr(pos) : 1;
        }
        long long ans = 0;
        int up = min(lim ? tmp_str[pos] - '0' : 9, limit);
        for (int i = 0; i <= up; ++i) {
            ans += dfs(s, limit, tmp_str, dp, pos + 1, lim && i == (tmp_str[pos] - '0'));
        }
        if (!lim) {
            dp[pos] = ans;
        }
        return ans;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string tmp_str = to_string(start - 1);
        vector<long long> dp(20, -1);
        long long a = dfs(s, limit, tmp_str, dp, 0, true);
        tmp_str = to_string(finish);
        ranges::fill(dp, -1);
        long long b = dfs(s, limit, tmp_str, dp, 0, true);
        return b - a;
    }
};
