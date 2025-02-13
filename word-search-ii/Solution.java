
import java.util.*;

class Solution {
    class Trie {
        Trie[] children = new Trie[26];
        int ref = -1;

        public void insert(String w, int ref) {
            Trie node = this;
            for (var i = 0; i < w.length(); ++i) {
                int ch = w.charAt(i);
                if (node.children[ch - 'a'] == null) {
                    node.children[ch - 'a'] = new Trie();
                }
                node = node.children[ch - 'a'];
            }
            node.ref = ref;
        }
    }

    private char[][] board;
    private String[] words;
    private final List<String> ans = new ArrayList<>();

    public List<String> findWords(char[][] board, String[] words) {
        this.board = board;
        this.words = words;
        Trie tree = new Trie();
        for (int i = 0; i < words.length; ++i) {
            tree.insert(words[i], i);
        }
        var n = board.length;
        var m = board[0].length;
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < m; ++j) {
                dfs(tree, i, j);
            }
        }
        return ans;
    }

    private void dfs(Trie node, int i, int j) {
        var ch = board[i][j];
        if (node.children[ch - 'a'] == null) {
            return;
        }
        node = node.children[ch - 'a'];
        if (node.ref != -1) {
            ans.add(words[node.ref]);
            node.ref = -1;
        }
        char c = board[i][j];
        board[i][j] = '#';
        int[] dirs = {-1, 0, 1, 0, -1};
        for (var k = 0; k < 4; ++k) {
            var ki = i + dirs[k];
            var kj = j + dirs[k + 1];
            if (ki >= 0 && ki < board.length && kj >= 0 && kj < board[0].length && board[ki][kj] != '#') {
                dfs(node, ki, kj);
            }
        }
        board[i][j] = c;
    }
}
