
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        const auto n = mat.size();
        for (auto k = 0; k < 4; ++k) {
            vector<vector<int>> g(n, vector<int>(n));
            for (auto i = 0; i < n; ++i) {
                for (auto j = 0; j < n; ++j) {
                    g[i][j] = mat[j][n - i - 1];
                }
            }
            if (g == target) {
                return true;
            }
            mat = g;
        }
        return false;
    }
};
