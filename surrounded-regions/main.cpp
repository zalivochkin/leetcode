
class Solution {
public:
    const vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, int i, int j, bool &is_surrounded) {
        const auto n = board.size();
        const auto m = board[0].size();
        const auto l = dirs.size();
        visited[i][j] = true;
        for (auto k = 0; k < l; ++k) {
            auto ki = i + dirs[k][0];
            auto kj = j + dirs[k][1];
            if (ki < 0 || ki == n || kj < 0 || kj == m) {
                is_surrounded = false;
                return;
            }
            if (visited[ki][kj] || board[ki][kj] == 'X') {
                continue;
            }
            dfs(board, visited, ki, kj, is_surrounded);
            if (!is_surrounded) {
                return;
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        const auto n = board.size();
        const auto m = board[0].size();
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (board[i][j] == 'X') {
                    continue;
                }
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                bool is_surrounded = true;
                dfs(board, visited, i, j, is_surrounded);
                if (is_surrounded) {
                    for (auto ki = 0; ki < n; ++ki) {
                        for (auto kj = 0; kj < m; ++kj) {
                            if (visited[ki][kj]) {
                                board[ki][kj] = 'X';
                            }
                        }
                    }
                }
            }
        }
    }
};
