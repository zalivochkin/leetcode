
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> field(m, vector<int>(n, 0));
        for (const auto &guard : guards) {
            field[guard[0]][guard[1]] = 2;
        }
        for (const auto &wall : walls) {
            field[wall[0]][wall[1]] = 2;
        }
        vector<int> dirs{-1, 0, 1, 0, -1};
        int i;
        int j;
        for (const auto &guard : guards) {
            for (int k = 0; k < 4; ++k) {
                i = guard[0];
                j = guard[1];
                for (int ti = i + dirs[k], tj = j + dirs[k + 1]; ti >= 0 && ti < m && tj >= 0 && tj < n && field[ti][tj] < 2; ti = i + dirs[k], tj = j + dirs[k + 1]) {
                    i += dirs[k];
                    j += dirs[k + 1];
                    field[i][j] = 1;
                }
            }
        }
        int res = 0;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (field[i][j] == 0) {
                    ++res;
                }
            }
        }
        return res;
    }
};
