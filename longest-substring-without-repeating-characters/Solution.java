
import java.util.*;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.isEmpty()) {
            return 0;
        }
        Set<Character> chars = new HashSet<>();
        int leftIndx = 0;
        chars.add(s.charAt(0));
        int maxLen = 1;
        for (int rightIndx = 1; rightIndx < s.length(); ++rightIndx) {
            while (chars.contains(s.charAt(rightIndx))) {
                chars.remove(s.charAt(leftIndx));
                ++leftIndx;
            }
            chars.add(s.charAt(rightIndx));
            maxLen = Math.max(maxLen, rightIndx - leftIndx + 1);
        }
        return maxLen;
    }
}
