
import java.util.*;

class Solution {
    public int[] constructDistancedSequence(int n) {
        int[] cnt = new int[n * 2];
        int[] path = new int[n * 2];
        Arrays.fill(cnt, 2);
        cnt[1] = 1;
        dfs(cnt, path, n, 1);
        int[] ans = new int[n * 2 - 1];
        for (var i = 0; i < ans.length; ++i) {
            ans[i] = path[i + 1];
        }
        return ans;
    }

    public boolean dfs(int[] cnt, int[] path, int n, int u) {
        if (u == n * 2) {
            return true;
        }
        if (path[u] > 0) {
            return dfs(cnt, path, n, u + 1);
        }
        for (var i = n; i > 1; --i) {
            if (cnt[i] > 0 && u + i < n * 2 && path[u + i] == 0) {
                cnt[i] = 0;
                path[u] = i;
                path[u + i] = i;
                if (dfs(cnt, path, n, u + 1)) {
                    return true;
                }
                cnt[i] = 2;
                path[u] = 0;
                path[u + i] = 0;
            }
        }
        if (cnt[1] > 0) {
            path[u] = 1;
            cnt[1] = 0;
            if (dfs(cnt, path, n, u + 1)) {
                return true;
            }
            cnt[1] = 1;
            path[u] = 0;
        }
        return false;
    }
}
