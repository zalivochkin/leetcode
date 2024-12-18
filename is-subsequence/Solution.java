import java.util.*;

class Solution {
    public boolean isSubsequence(String s, String t) {
        int sIndx = 0;
        int tIndx = 0;
        while (sIndx < s.length() && tIndx < t.length()) {
            if (s.charAt(sIndx) == t.charAt(tIndx)) {
                ++sIndx;
                ++tIndx;
            } else {
                ++tIndx;
            }
        }
        return sIndx == s.length();
    }
}
