
class Solution {
public:
    int dfs(vector<int> &dp, const vector<int> &arr, const int n, const int i, const int d) {
        if (dp[i] > 0) {
            return dp[i];
        }
        int res = 1;
        for (int j = i + 1; j <= min(i + d, n - 1); ++j) {
            if (arr[j] >= arr[i]) {
                break;
            }
            res = max(res, 1 + dfs(dp, arr, n, j, d));
        }
        for (int j = i - 1; j >= max(0, i - d); --j) {
            if (arr[j] >= arr[i]) {
                break;
            }
            res = max(res, 1 + dfs(dp, arr, n, j, d));
        }
        return dp[i] = res;
    }
    int maxJumps(vector<int>& arr, int d) {
        const int n = arr.size();
        vector<int> dp(n, 0);
        int res = 1;
        for (auto i = 0; i < n; ++i) {
            res = max(res, dfs(dp, arr, n, i, d));
        }
        return res;
    }
};
