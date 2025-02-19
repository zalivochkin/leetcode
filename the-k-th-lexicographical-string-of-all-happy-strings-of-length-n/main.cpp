
class Solution {
public:
    void dfs(vector<string> &ans, string s, int n) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }
        for (auto c = 'a'; c <= 'c'; ++c) {
            if (!s.empty() && s.back() == c) {
                continue;
            }
            s.push_back(c);
            dfs(ans, s, n);
            s.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        dfs(ans, "", n);
        return ans.size() < k ? "" : ans[k - 1];
    }
};
