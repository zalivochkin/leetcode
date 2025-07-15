
class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) {
            return false;
        }
        boolean hasVowel = false;
        boolean hasConsonant = false;
        boolean[] vs = new boolean[26 + 'a'];
        for (var ch : "aeiou".toCharArray()) {
            vs[ch] = true;
        }
        for (var ch : word.toCharArray()) {
            if (Character.isAlphabetic(ch)) {
                if (vs[Character.toLowerCase(ch)]) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!Character.isDigit(ch)) {
                return false;
            }
        }
        return hasVowel && hasConsonant;
    }
}
