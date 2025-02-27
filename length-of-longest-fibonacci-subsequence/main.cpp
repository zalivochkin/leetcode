
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        const auto n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<int, int> mp;
        for (auto i = 0; i < n; ++i) {
            mp[arr[i]] = i;
            for (auto j = 0; j < i; ++j) {
                dp[i][j] = 2;
            }
        }
        int ans = 0;
        for (auto i = 2; i < n; ++i) {
            for (auto j = 1; j < i; ++j) {
                auto it = mp.find(arr[i] - arr[j]);
                if (it != mp.end() && it->second < j) {
                    dp[i][j] = std::max(dp[i][j], dp[j][it->second] + 1);
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
