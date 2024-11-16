
class Solution {
public:
    int numOfArrays(const int length, const int max_val, const int n_max) {
        if(n_max == 0) {
            return 0;
        }
        constexpr int mod = 1'000'000'007;
        vector<vector<int>> dp_prev(n_max + 1, vector(max_val + 1, 0)),
                            dp(n_max + 1, vector(max_val + 1, 0));
        fill(dp[0].begin(), dp[0].end(), 1);
        for(int l = 1; l <= length; ++l) {
            swap(dp_prev, dp);
            fill(dp[0].begin(), dp[0].end(), 0);
            for(int k = 1; k <= min(l, n_max); ++k) {
                int64_t count = 0;
                for(int m = 1; m <= max_val; ++m) {
                    count += int64_t{ dp_prev[k][m] + mod - dp_prev[k][m - 1] } * int64_t{ m };
                    count += int64_t{ dp_prev[k - 1][m - 1] };
                    count %= int64_t{ mod };
                    dp[k][m] = static_cast<int>(count);
                }
            }
        }
        return dp[n_max][max_val];
    }
};
