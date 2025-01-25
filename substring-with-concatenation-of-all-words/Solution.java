
import java.util.*;

class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        final var n = s.length();
        final var m = words.length;
        final var k = words[0].length();
        Map<String, Integer> cnts = new HashMap<>();
        for (var w : words) {
            cnts.merge(w, 1, Integer::sum);
        }
        List<Integer> res = new ArrayList<>();
        for (var i = 0; i < k; ++i) {
            Map<String, Integer> cnt1 = new HashMap<>();
            int lft = i;
            int rght = i;
            int cnt = 0;
            while (rght + k <= n) {
                var wrd = s.substring(rght, rght + k);
                rght += k;
                if (!cnts.containsKey(wrd)) {
                    cnt1.clear();
                    lft = rght;
                    cnt = 0;
                    continue;
                }
                cnt1.merge(wrd, 1, Integer::sum);
                ++cnt;
                while (cnt1.get(wrd) > cnts.get(wrd)) {
                    String remove = s.substring(lft, lft + k);
                    lft += k;
                    cnt1.merge(remove, -1, Integer::sum);
                    --cnt;
                }
                if (cnt == m) {
                    res.add(lft);
                }
            }
        }
        return res;
    }
}
