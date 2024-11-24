
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int min_value = numeric_limits<int>::max();
        long long sum = 0;
        int neg_count = 0;
        const auto n = matrix.size();
        const auto m = matrix[0].size();
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (matrix[i][j] > 0) {
                    min_value = min(min_value, matrix[i][j]);
                    sum += matrix[i][j];
                } else {
                    neg_count++;
                    min_value = min(min_value, 0 - matrix[i][j]);
                    sum -= matrix[i][j];
                }
            }
        }
        if (neg_count % 2 != 0) {
            sum -= 2 * min_value;
        }
        return sum;
    }
};
