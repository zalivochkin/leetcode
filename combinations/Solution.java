
import java.util.*;

class Solution {
    private List<List<Integer>> ans = new ArrayList<>();
    private List<Integer> tmpAns = new ArrayList<>();
    private int n;
    private int k;

    public List<List<Integer>> combine(int n, int k) {
        this.n = n;
        this.k = k;
        dfs(1);
        return ans;
    }

    private void dfs(int i) {
        if (tmpAns.size() == k) {
            ans.add(new ArrayList<>(tmpAns));
            return;
        }
        if (i > n) {
            return;
        }
        for (var j = i; j <= n; ++j) {
            tmpAns.add(j);
            dfs(j + 1);
            tmpAns.remove(tmpAns.size() - 1);
        }
    }
}
