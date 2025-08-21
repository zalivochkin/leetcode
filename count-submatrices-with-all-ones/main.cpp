
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const auto n = mat.size();
        const auto m = mat[0].size();
        vector<vector<int>> g(n, vector<int>(m));
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (mat[i][j] == 1) {
                    g[i][j] = j == 0 ? 1 : 1 + g[i][j - 1];
                }
            }
        }
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                int col = 1 << 30;
                for (int k = i; k >= 0 && col > 0; --k) {
                    col = min(col, g[k][j]);
                    ans += col;
                }
            }
        }
        return ans;
    }
};
