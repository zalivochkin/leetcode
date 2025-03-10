
class Solution {
    boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long fn(String word, int k) {
        long ans = 0;
        int lft = 0;
        int nonVowels = 0;
        Map<Character, Integer> cnt = new HashMap<>(5);
        for (var c : word.toCharArray()) {
            if (isVowel(c)) {
                cnt.merge(c, 1, Integer::sum);
            } else {
                ++nonVowels;
            }
            while (nonVowels >= k && cnt.size() == 5) {
                var d = word.charAt(lft++);
                if (isVowel(d)) {
                    if (cnt.merge(d, -1, Integer::sum) == 0) {
                        cnt.remove(d);
                    }
                } else {
                    --nonVowels;
                }
            }
            ans += lft;
        }
        return ans;
    }

    public long countOfSubstrings(String word, int k) {
        return fn(word, k) - fn(word, k + 1);
    }
}
