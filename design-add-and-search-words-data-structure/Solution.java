
import java.util.*;

class WordDictionary {
    class Trie {
        public Trie[] children;
        public boolean isEnd;

        public Trie() {
            children = new Trie[26];
        }

        public void insert(String word) {
            Trie node = this;
            for (var ch : word.toCharArray()) {
                if (node.children[ch - 'a'] == null) {
                    node.children[ch - 'a'] = new Trie();
                }
                node = node.children[ch - 'a'];
            }
            node.isEnd = true;
        }

        public boolean search(String word) {
            Trie node = searchPrefix(word);
            return node != null && node.isEnd;
        }

        public boolean startsWith(String prefix) {
            Trie node = searchPrefix(prefix);
            return node != null;
        }

        private Trie searchPrefix(String s) {
            Trie node = this;
            for (var ch : s.toCharArray()) {
                if (node.children[ch - 'a'] == null) {
                    return null;
                }
                node = node.children[ch - 'a'];
            }
            return node;
        }
    }

    private final Trie trie;

    public WordDictionary() {
        trie = new Trie();
    }

    public void addWord(String word) {
        trie.insert(word);
    }

    public boolean search(String word) {
        return dfs(word, trie);
    }

    private boolean dfs(String word, Trie node) {
        for (var i = 0; i < word.length(); ++i) {
            var c = word.charAt(i);
            if (c != '.' && node.children[c - 'a'] == null) {
                return false;
            }
            if (c == '.') {
                for (Trie child : node.children) {
                    if (child != null && dfs(word.substring(i + 1), child)) {
                        return true;
                    }
                }
                return false;
            }
            node = node.children[c - 'a'];
        }
        return node.isEnd;
    }
}
