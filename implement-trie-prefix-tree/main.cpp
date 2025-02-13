
class Trie {
private:
    vector<Trie*> children;
    bool is_end;

    Trie* searchPrefix(string s) {
        Trie* node = this;
        for (const auto ch : s) {
            if (!node->children[ch - 'a']) {
                return nullptr;
            }
            node = node->children[ch - 'a'];
        }
        return node;
    }

public:
    Trie() : children(26), is_end(false) {}

    void insert(string word) {
        Trie* node = this;
        for (const auto ch : word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->is_end = true;
    }

    bool search(string word) {
        Trie* node = searchPrefix(word);
        return node != nullptr && node->is_end;
    }

    bool startsWith(string prefix) {
        Trie* node = searchPrefix(prefix);
        return node != nullptr;
    }
};
