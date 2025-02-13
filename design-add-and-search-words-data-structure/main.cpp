
class Trie {
public:
    vector<Trie*> children;
    bool is_end;

    Trie() : children(26), is_end(false) {}

    Trie* searchPrefix(const string & s) {
        Trie* node = this;
        for (const auto ch : s) {
            if (!node->children[ch - 'a']) {
                return nullptr;
            }
            node = node->children[ch - 'a'];
        }
        return node;
    }

    void insert(const string &word) {
        Trie* node = this;
        for (const auto ch : word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->is_end = true;
    }

    bool search(const string & word) {
        Trie* node = searchPrefix(word);
        return node != nullptr && node->is_end;
    }

    bool startsWith(const string & prefix) {
        Trie* node = searchPrefix(prefix);
        return node != nullptr;
    }
};

class WordDictionary {
private:
    Trie* root;

public:
    WordDictionary() : root(new Trie) {}

    void addWord(string word) {
        root->insert(word);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(const string& word, int i, Trie* cur) {
        if (i == word.size()) {
            return cur->is_end;
        }
        if (word[i] != '.') {
            Trie* child = cur->children[word[i] - 'a'];
            if (child != nullptr && dfs(word, i + 1, child)) {
                return true;
            }
        } else {
            for (Trie* child : cur->children) {
                if (child != nullptr && dfs(word, i + 1, child)) {
                    return true;
                }
            }
        }
        return false;
    }
};
