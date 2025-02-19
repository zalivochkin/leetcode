
import java.util.*;

class Solution {
    public void dfs(List<String> ans, String s, int n) {
        if (s.length() == n) {
            ans.add(s);
            return;
        }
        for (var ch : "abc".toCharArray()) {
            if (!s.isEmpty() && s.charAt(s.length() - 1) == ch) {
                continue;
            }
            dfs(ans, s + ch, n);
        }
    }

    public String getHappyString(int n, int k) {
        List<String> ans = new ArrayList<>();
        dfs(ans, "", n);
        return ans.size() < k ? "" : ans.get(k - 1);
    }
}
