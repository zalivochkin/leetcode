
import java.util.*;

class Solution {
    public String reverseWords(String s) {
        StringBuilder wordSb = new StringBuilder();
        Stack<String> st = new Stack<>();
        for (var ch : s.toCharArray()) {
            if (" ".equals(String.valueOf(ch))) {
                if (wordSb.length() > 0) {
                    st.push(wordSb.toString());
                    wordSb = new StringBuilder();
                }
            } else {
                wordSb.append(String.valueOf(ch));
            }
        }
        if (wordSb.length() > 0) {
            st.push(wordSb.toString());
        }
        StringBuilder resultSb = new StringBuilder();
        while (!st.isEmpty()) {
            resultSb.append(st.peek());
            st.pop();
            if (!st.isEmpty()) {
                resultSb.append(" ");
            }
        }
        return resultSb.toString();
    }
}
