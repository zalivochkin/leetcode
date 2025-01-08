
import java.util.*;

class Solution {
    public int countPrefixSuffixPairs(String[] words) {
        final var n = words.length;
        int res = 0;
        for (var i = 0; i < n; ++i) {
            String str1 = words[i];
            for (var j = i + 1; j < n; ++j) {
                String str2 = words[j];
                if (str2.startsWith(str1) && str2.endsWith(str1)) {
                    ++res;
                }
            }
        }
        return res;
    }
}
