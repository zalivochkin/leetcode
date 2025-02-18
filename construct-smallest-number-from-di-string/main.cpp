
class Solution {
public:
    string smallestNumber(string pattern) {
        string ans;
        vector<bool> vis(10, false);
        string cur_ans;
        dfs(pattern, ans, vis, cur_ans, 0);
        return ans;
    }

    void dfs(string &pattern, string &ans, vector<bool> &vis, string &cur_ans, int u) {
        if (ans != "") {
            return;
        }
        if (u == pattern.size() + 1) {
            ans = cur_ans;
            return;
        }
        for (auto i = 1; i < 10; ++i) {
            if (!vis[i]) {
                if (u && pattern[u - 1] == 'I' && cur_ans.back() - '0' >= i) {
                    continue;
                }
                if (u && pattern[u - 1] == 'D' && cur_ans.back() - '0' <= i) {
                    continue;
                }
                vis[i] = true;
                cur_ans += to_string(i);
                dfs(pattern, ans, vis, cur_ans, u + 1);
                cur_ans.pop_back();
                vis[i] = false;
            }
        }
    }
};
