
import java.util.*;

class Trie {
    private Trie[] children;
    private boolean isEnd;

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
