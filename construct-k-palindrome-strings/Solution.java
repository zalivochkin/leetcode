
import java.util.*;

class Solution {
    public boolean canConstruct(String s, int k) {
        if (s.length() < k) {
            return false;
        }
        var cnts = new int[26];
        for (var ch : s.toCharArray()) {
            cnts[ch - 'a'] += 1;
        }
        int odd_counts = 0;
        for (var cnt : cnts) {
            odd_counts += cnt & 1;
        }
        return odd_counts <= k;
    }
}
