
import java.util.*;

class Solution {
    private final boolean[] vis = new boolean[10];
    private final StringBuilder tmpAns = new StringBuilder();
    private String Pattern;
    private String ans;

    public String smallestNumber(String pattern) {
        Pattern = pattern;
        dfs(0);
        return ans;
    }

    private void dfs(int u) {
        if (ans != null) {
            return;
        }
        if (u == Pattern.length() + 1) {
            ans = tmpAns.toString();
            return;
        }
        for (var i = 1; i < 10; ++i) {
            if (!vis[i]) {
                if (u > 0 && Pattern.charAt(u - 1) == 'I' && tmpAns.charAt(u - 1) - '0' >= i) {
                    continue;
                }
                if (u > 0 && Pattern.charAt(u - 1) == 'D' && tmpAns.charAt(u - 1) - '0' <= i) {
                    continue;
                }
                vis[i] = true;
                tmpAns.append(i);
                dfs(u + 1);
                tmpAns.deleteCharAt(tmpAns.length() - 1);
                vis[i] = false;
            }
        }
    }
}
