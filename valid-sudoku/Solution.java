
import java.util.*;

class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (var i = 0; i < board.length; ++i) {
            Set<Character> set = new HashSet<>();
            for (var j = 0; j < board.length; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (set.contains(board[i][j])) {
                    return false;
                }
                set.add(board[i][j]);
            }
        }
        for (var i = 0; i < board.length; ++i) {
            Set<Character> set = new HashSet<>();
            for (var j = 0; j < board.length; ++j) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (set.contains(board[j][i])) {
                    return false;
                }
                set.add(board[j][i]);
            }
        }
        for (var bi = 0; bi < board.length; bi += 3) {
            for (var bj = 0; bj < board.length; bj += 3) {
                Set<Character> set = new HashSet<>();
                for (var i = 0; i < 3; ++i) {
                    for (var j = 0; j < 3; ++j) {
                        if (board[bi + i][bj + j] == '.') {
                            continue;
                        }
                        if (set.contains(board[bi + i][bj + j])) {
                            return false;
                        }
                        set.add(board[bi + i][bj + j]);
                    }
                }
            }
        }
        return true;
    }
}
