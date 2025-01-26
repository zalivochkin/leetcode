
import java.util.*;

class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        Map<Character, Integer> mp = new HashMap<>();
        for (var ch : s.toCharArray()) {
            mp.merge(ch, 1, Integer::sum);
        }
        for (var ch : t.toCharArray()) {
            if (!mp.containsKey(ch)) {
                return false;
            }
            mp.merge(ch, -1, Integer::sum);
            if (mp.get(ch) == 0) {
                mp.remove(ch);
            }
        }
        return mp.isEmpty();
    }
}
