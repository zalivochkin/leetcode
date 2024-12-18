
import java.util.*;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        Map<Character, String> map = new HashMap<>();
        Map<String, Character> rmap = new HashMap<>();
        int chIndx = 0;
        for (var word : s.split(" ")) {
            if (chIndx == pattern.length()) {
                return false;
            }
            if (map.containsKey(pattern.charAt(chIndx))) {
                if (!word.equals(map.get(pattern.charAt(chIndx)))) {
                    return false;
                }
            } else {
                map.put(pattern.charAt(chIndx), word);
            }
            if (rmap.containsKey(word)) {
                if (rmap.get(word) != pattern.charAt(chIndx)) {
                    return false;
                }
            } else {
                rmap.put(word, pattern.charAt(chIndx));
            }
            ++chIndx;
        }
        return chIndx == pattern.length();
    }
}
