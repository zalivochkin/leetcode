
import java.util.*;

class Solution {
    public int prefixCount(String[] words, String pref) {
        int cnt = 0;
        for (final var word : words) {
            if (word.startsWith(pref)) {
                ++cnt;
            }
        }
        return cnt;
    }
}
