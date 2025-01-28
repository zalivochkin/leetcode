
import java.util.*;

class Solution {
    public String simplifyPath(String path) {
        Deque<String> st = new ArrayDeque<>();
        for (final var s : path.split("/")) {
            if (".".equals(s) || s.isEmpty()) {
                continue;
            } else if ("..".equals(s)) {
                if (!st.isEmpty()) {
                    st.pollLast();
                }
            } else {
                st.addLast(s);
            }
        }
        return "/" + String.join("/", st);
    }
}
