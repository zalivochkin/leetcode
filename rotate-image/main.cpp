
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const auto n = matrix.size();
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
