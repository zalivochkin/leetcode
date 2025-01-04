
import java.util.*;

class Solution {
    public int countPalindromicSubsequence(String s) {
        int res = 0;
        int lft;
        int rght;
        Set<Character> cs = new HashSet<>();
        for (var c = 'a'; c <= 'z'; ++c) {
            lft = s.indexOf(c);
            rght = s.lastIndexOf(c);
            cs.clear();
            for (var i = lft + 1; i < rght; ++i) {
                cs.add(s.charAt(i));
            }
            res += cs.size();
        }
        return res;
    }
}
