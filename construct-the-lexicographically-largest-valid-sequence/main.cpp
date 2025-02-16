
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> cnt(n * 2, 2);;
        vector<int> path(n * 2);
        cnt[1] = 1;
        dfs(cnt, path, n, 1);
        vector<int> ans;
        for (auto i = 1; i < n * 2; ++i) {
            ans.push_back(path[i]);
        }
        return ans;
    }

    bool dfs(vector<int> &cnt, vector<int> &path, int n, int u) {
        if (u == n * 2) {
            return true;
        }
        if (path[u]) {
            return dfs(cnt, path, n, u + 1);
        }
        for (auto i = n; i > 1; --i) {
            if (cnt[i] && u + i < n * 2 && !path[u + i]) {
                path[u] = path[u + i] = i;
                cnt[i] = 0;
                if (dfs(cnt, path, n, u + 1)) {
                    return true;
                }
                cnt[i] = 2;
                path[u] = path[u + i] = 0;
            }
        }
        if (cnt[1]) {
            path[u] = 1;
            cnt[1] = 0;
            if (dfs(cnt, path, n, (u + 1))) {
                return true;
            }
            cnt[1] = 1;
            path[u] = 0;
        }
        return false;
    }
};
