
import java.util.*;

class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if (digits.isEmpty()) {
            return ans;
        }
        ans.add("");
        String[] d = new String[] {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (var ch : digits.toCharArray()) {
            String s = d[ch - '2'];
            List<String> t = new ArrayList<>();
            for (String s2 : ans) {
                for (String s3 : s.split("")) {
                    t.add(s2 + s3);
                }
            }
            ans = t;
        }
        return ans;
    }
}
