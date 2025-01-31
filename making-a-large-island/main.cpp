
class Solution {
public:
    const int dirs[5] = {-1, 0, 1, 0, -1};
    int dfs(vector<vector<int>>& grid, vector<vector<int>> &p, int root, int cnt[], int i, int j) {
        const auto n = grid.size();
        p[i][j] = root;
        ++cnt[root];
        for (int k = 0; k < 4; ++k) {
            int ki = i + dirs[k];
            int kj = j + dirs[k + 1];
            if (ki >= 0 && ki < n && kj >= 0 && kj < n && grid[ki][kj] && !p[ki][kj]) {
                dfs(grid, p, root, cnt, ki, kj);
            }
        }
        return cnt[root];
    }

    int largestIsland(vector<vector<int>>& grid) {
        const auto n = grid.size();
        vector<vector<int>> p(n, vector<int>(n, 0));
        int cnts[n * n + 1];
        memset(cnts, 0, sizeof(cnts));
        int root = 0;
        int res = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (grid[i][j] && !p[i][j]) {
                    ++root;
                    res = max(res, dfs(grid, p, root, cnts, i, j));
                }
            }
        }
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    unordered_set<int> s;
                    for (auto k = 0; k < 4; ++k) {
                        int ki = i + dirs[k];
                        int kj = j + dirs[k + 1];
                        if (ki >= 0 && ki < n && kj >= 0 && kj < n) {
                            s.insert(p[ki][kj]);
                        }
                    }
                    int cnt = 1;
                    for (auto x : s) {
                        cnt += cnts[x];
                    }
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};
