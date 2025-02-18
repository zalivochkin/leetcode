
import java.util.*;

class Solution {
    public int n;
    public int ans;
    public boolean[] cols = new boolean[10];
    public boolean[] dg = new boolean[20];
    public boolean[] udg = new boolean[20];

    public void dfs(int i) {
        if (i == n) {
            ++ans;
            return;
        }
        for (var j = 0; j < n; ++j) {
            int a = i + j;
            int b = i - j + n;
            if (cols[j] || dg[a] || udg[b]) {
                continue;
            }
            cols[j] = true;
            dg[a] = true;
            udg[b] = true;
            dfs(i + 1);
            cols[j] = false;
            dg[a] = false;
            udg[b] = false;
        }
    }

    public int totalNQueens(int n) {
        this.n = n;
        dfs(0);
        return ans;
    }
}
