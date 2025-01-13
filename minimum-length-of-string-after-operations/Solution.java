
import java.util.*;

class Solution {
    public int minimumLength(String s) {
        Map<Character, Integer> mp = new HashMap<>();
        for (var ch : s.toCharArray()) {
            mp.merge(ch, 1, Integer::sum);
        }
        int res = 0;
        for (var entr : mp.entrySet()) {
            if (entr.getValue() > 2) {
                res += (entr.getValue() % 2) == 0 ? 2 : 1;
            } else {
                res += entr.getValue();
            }
        }
        return res;
    }
}
