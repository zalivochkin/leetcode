
class Solution {
public:
    int check(const vector<vector<int>>& grid, int i, int j) {
        const auto m = grid.size();
        const auto n = grid[0].size();
        if (i + 3 > m || j + 3 > n) {
            return 0;
        }
        vector<int> cnt(16);
        vector<int> row(3);
        vector<int> col(3);
        int a = 0, b = 0;
        for (int x = i; x < i + 3; ++x) {
            for (int y = j; y < j + 3; ++y) {
                int v = grid[x][y];
                if (v < 1 || v > 9 || ++cnt[v] > 1) {
                    return 0;
                }
                row[x - i] += v;
                col[y - j] += v;
                if (x - i == y - j) {
                    a += v;
                }
                if (x - i + y - j == 2) {
                    b += v;
                }
            }
        }
        if (a != b) {
            return 0;
        }
        for (int k = 0; k < 3; ++k) {
            if (row[k] != a || col[k] != a) {
                return 0;
            }
        }
        return 1;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const auto m = grid.size();
        const auto n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += check(grid, i, j);
            }
        }
        return ans;
    }
};
