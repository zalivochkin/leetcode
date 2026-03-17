
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const auto n = matrix.size();
        const auto m = matrix[0].size();
        for (auto i = 1; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (matrix[i][j]) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (auto &row : matrix) {
            sort(row.rbegin(), row.rend());
            for (auto j = 0; j < m; ++j) {
                ans = max(ans, (j + 1) * row[j]);
            }
        }
        return ans;
    }
};
