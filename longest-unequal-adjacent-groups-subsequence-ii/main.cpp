
class Solution {
public:
    bool check(string& s, string& t) {
        if (s.size() != t.size()) {
            return false;
        }
        int cnt = 0;
        const auto n = s.size();
        for (auto i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                ++cnt;
            }
        }
        return cnt == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const auto n = words.size();
        vector<int> f(n, 1);
        vector<int> g(n, -1);
        int mx = 1;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && f[i] < f[j] + 1 && check(words[i], words[j])) {
                    f[i] = f[j] + 1;
                    g[i] = j;
                    mx = max(mx, f[i]);
                }
            }
        }
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (f[i] == mx) {
                for (int j = i; ~j; j = g[j]) {
                    ans.emplace_back(words[j]);
                }
                break;
            }
        }
        ranges::reverse(ans);
        return ans;
    }
};
