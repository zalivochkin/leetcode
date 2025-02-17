
import java.util.*;

class Solution {
    public int dfs(Map<Character, Integer> cnts) {
        int res = 0;
        for (var entr : cnts.entrySet()) {
            if (entr.getValue() > 0) {
                ++res;
                cnts.merge(entr.getKey(), -1, Integer::sum);
                res += dfs(cnts);
                cnts.merge(entr.getKey(), 1, Integer::sum);
            }
        }
        return res;
    }

    public int numTilePossibilities(String tiles) {
        Map<Character, Integer> cnts = new HashMap<>();
        for (var ch : tiles.toCharArray()) {
            cnts.merge(ch, 1, Integer::sum);
        }
        return dfs(cnts);
    }
}
