
import java.util.*;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (var ch : s.toCharArray()) {
            if (st.isEmpty()) {
                if (ch == ')' || ch == '}' || ch == ']') {
                    return false;
                }
                st.push(ch);
            } else {
                if (ch == '(' || ch == '{' || ch == '[') {
                    st.push(ch);
                } else {
                    if (ch == ')' && st.peek() != '(') {
                        return false;
                    } else if (ch == '}' && st.peek() != '{') {
                        return false;
                    } else if (ch == ']' && st.peek() != '[') {
                        return false;
                    }
                    st.pop();
                }
            }
        }
        return st.isEmpty();
    }
}
