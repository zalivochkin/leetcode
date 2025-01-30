
import java.util.*;

class Solution {
    public void dfs(int[] candidates, int target, int curIndx, List<List<Integer>> res, Deque<Integer> candidate) {
        if (target == 0) {
            res.add(new ArrayList<>(candidate));
        }
        final var n = candidates.length;
        for (var i = curIndx; i < n; ++i) {
            if (candidates[i] <= target) {
                candidate.push(candidates[i]);
                dfs(candidates, target - candidates[i], i, res, candidate);
                candidate.pop();
            }
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Deque<Integer> candidate = new ArrayDeque<>();
        dfs(candidates, target, 0, res, candidate);
        return res;
    }
}
