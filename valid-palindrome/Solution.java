
import java.util.*;

class Solution {
    public boolean isPalindrome(String s) {
        if (s.length() == 1) {
            return true;
        }
        int leftIndx = 0;
        int rightIndx = s.length() - 1;
        while (rightIndx > leftIndx) {
            if (!Character.isDigit(s.charAt(leftIndx)) && !Character.isAlphabetic(s.charAt(leftIndx))) {
                ++leftIndx;
            } else if (!Character.isDigit(s.charAt(rightIndx)) && !Character.isAlphabetic(s.charAt(rightIndx))) {
                --rightIndx;
            } else if (Character.toLowerCase(s.charAt(leftIndx)) != Character.toLowerCase(s.charAt(rightIndx))) {
                return false;
            } else {
                ++leftIndx;
                --rightIndx;
            }
        }
        return true;
    }
}
