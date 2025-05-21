
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const auto n = matrix.size();
        const auto m = matrix[0].size();
        vector<bool> rows(n);
        vector<bool> cols(m);
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (!matrix[i][j]) {
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
