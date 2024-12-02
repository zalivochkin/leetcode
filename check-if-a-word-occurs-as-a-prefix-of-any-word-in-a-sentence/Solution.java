public class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        var n = sentence.length();
        var m = searchWord.length();
        int res = 1;
        int j;
        for (var i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (i + j == n) {
                    return -1;
                }
                if (sentence.charAt(i + j) == ' ' || sentence.charAt(i + j) != searchWord.charAt(j)) {
                    i += j;
                    break;
                }
            }
            if (j == m) {
                return res;
            }
            while (i < n && sentence.charAt(i) != ' ') {
                ++i;
            }
            res++;
        }
        return -1;
    }
}
