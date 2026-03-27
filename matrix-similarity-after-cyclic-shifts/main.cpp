
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        const auto n = mat.size();
        const auto m = mat[0].size();
        k %= m;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (i % 2 == 1 && mat[i][j] != mat[i][(j + k) % m]) {
                    return false;
                }
                if (i % 2 == 0 && mat[i][j] != mat[i][(j - k + m) % m]) {
                    return false;
                }
            }
        }
        return true;
    }
};
