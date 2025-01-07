
import java.util.*;

class Solution {
    public List<String> stringMatching(String[] words) {
        final var n = words.length;
        List<String> res = new ArrayList<>();
        for (var i = 0; i < n; ++i) {
            for (var j = 0; j < n; ++j) {
                if (i != j && words[j].length() >= words[i].length() && words[j].contains(words[i])) {
                    res.add(words[i]);
                    break;
                }
            }
        }
        return res;
    }
}
