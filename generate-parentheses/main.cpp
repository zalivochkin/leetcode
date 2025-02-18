
class Solution {
public:
    void dfs(vector<string> &ans, int l, int r, string t, int n) {
        if (l > n || r > n || l < r) {
            return;
        }
        if (l == n && r == n) {
            ans.push_back(t);
            return;
        }
        dfs(ans, l + 1, r, t + "(", n);
        dfs(ans, l, r + 1, t + ")", n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, 0, 0, "", n);
        return ans;
    }
};
