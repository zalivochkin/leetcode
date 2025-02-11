
import java.util.*;

class Solution {
    public String clearDigits(String s) {
        StringBuilder stk = new StringBuilder();
        for (final var ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                stk.deleteCharAt(stk.length() - 1);
            } else {
                stk.append(ch);
            }
        }
        return stk.toString();
    }
}
