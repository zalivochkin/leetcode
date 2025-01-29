
import java.util.*;

class Solution {
    boolean isSurrounded = false;
    int[][] dirs = new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public void dfs(char[][] board, boolean[][] visited, int i, int j) {
        final var n = board.length;
        final var m = board[0].length;
        final var l = dirs.length;
        visited[i][j] = true;
        for (var k = 0; k < l; ++k) {
            var ki = i + dirs[k][0];
            var kj = j + dirs[k][1];
            if (ki < 0 || ki == n || kj < 0 || kj == m) {
                isSurrounded = false;
                return;
            }
            dfs(board, visited, ki, kj);
            if (!isSurrounded) {
                return;
            }
        }
    }
    public void solve(char[][] board) {
        final var n = board.length;
        final var m = board[0].length;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                if (board[i][j] == 'X') {
                    continue;
                }
                boolean[][] visited = new boolean[n][m];
                isSurrounded = true;
                dfs(board, visited, i, j);
                if (isSurrounded) {
                    for (var ki = 0; ki < n; ++ki) {
                        for (var kj = 0; kj < m; ++kj) {
                            if (visited[ki][kj]) {
                                board[ki][kj] = 'X';
                            }
                        }
                    }
                }
            }
        }
    }
}
