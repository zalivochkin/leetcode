
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        auto n = houses.size();
        sort(houses.begin(), houses.end());
        vector<int> st(n + 1, 0);
        vector<int>  dp(n, INT_MAX / 2);
        for (int i = 0; i < n; ++i) {
            st[i + 1] = st[i] + houses[i];
        }
        for (int ki = 1; ki <= k; ++ki) {
            for (int j = n - 1; j > ki - 2; --j) {
                for (int i = ki - 2; i < j; ++i) {
                    int m1 = (i + j + 1) / 2;
                    int m2 = (i + j + 2) / 2;
                    int last = (st[j + 1] - st[m2]) - (st[m1 + 1] - st[i + 1]);
                    dp[j] = min(dp[j], (i >= 0 ? dp[i] : 0) + last);
                }
            }
        }
        return dp[n - 1];
    }
};
