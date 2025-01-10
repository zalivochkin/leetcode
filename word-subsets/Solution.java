
import java.util.*;

class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] max_cnt = new int[26];
        int[] tmp_cnt = new int[26];
        for (var word : words2) {
            Arrays.fill(tmp_cnt, 0);
            for (var i = 0; i < word.length(); ++i) {
                tmp_cnt[word.charAt(i) - 'a']++;
            }
            for (var i = 0; i < 26; ++i) {
                max_cnt[i] = Math.max(max_cnt[i], tmp_cnt[i]);
            }
        }
        List<String> res = new ArrayList<>();
        boolean isUnique;
        for (var word : words1) {
            Arrays.fill(tmp_cnt, 0);
            for (var i = 0; i < word.length(); ++i) {
                tmp_cnt[word.charAt(i) - 'a']++;
            }
            isUnique = true;
            for (var i = 0; i < 26; ++i) {
                if (max_cnt[i] > tmp_cnt[i]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                res.add(word);
            }
        }
        return res;
    }
}
