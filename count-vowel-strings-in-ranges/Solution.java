
import java.util.*;

class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        var n = words.length;
        var m = queries.length;
        Set<Character> vowels = Set.of('a', 'e', 'i', 'o', 'u');
        List<Integer> prefSum = new ArrayList<>(n + 1);
        prefSum.add(0);
        for (var i = 0; i < n; ++i) {
            prefSum.add(prefSum.get(i) + (vowels.contains(words[i].charAt(0)) && vowels.contains(words[i].charAt(words[i].length() - 1)) ? 1 : 0));
        }
        int[] res = new int[m];
        for (var i = 0; i < m; ++i) {
            res[i] = prefSum.get(queries[i][1] + 1) - prefSum.get(queries[i][0]);
        }
        return res;
    }
}
