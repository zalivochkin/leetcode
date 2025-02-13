
class Trie {
public:
    vector<Trie*> children;
    int ref;

    Trie() : children(26, nullptr), ref(-1) {}

    void insert(const string& w, int ref_) {
        Trie* node = this;
        for (const auto ch : w) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->ref = ref_;
    }
};

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<string>& words, Trie* node, int i, int j, vector<string> &ans) {
        int idx = board[i][j] - 'a';
        if (!node->children[idx]) {
            return ;
        }
        node = node->children[idx];
        if (node->ref != -1) {
            ans.emplace_back(words[node->ref]);
            node->ref = -1;
        }
        int dirs[5] = {-1, 0, 1, 0, -1};
        char c = board[i][j];
        board[i][j] = '#';
        const auto m = board.size();
        const auto n = board[0].size();
        for (auto k = 0; k < 4; ++k) {
            int ki = i + dirs[k];
            int kj = j + dirs[k + 1];
            if (ki >= 0 && ki < m && kj >= 0 && kj < n && board[ki][kj] != '#') {
                dfs(board, words, node, ki, kj, ans);
            }
        }
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* tree = new Trie();
        for (int i = 0; i < words.size(); ++i) {
            tree->insert(words[i], i);
        }
        vector<string> ans;
        const auto m = board.size();
        const auto n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, words, tree, i, j, ans);
            }
        }
        return ans;
    }
};
