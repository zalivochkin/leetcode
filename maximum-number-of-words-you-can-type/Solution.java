
class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        boolean[] broken_letters = new boolean[123];
        for (char ch : brokenLetters.toCharArray()) {
            broken_letters[ch] = true;
        }
        int ans = 0;
        for (String word : text.split(" ")) {
            for (char ch : word.toCharArray()) {
                if (broken_letters[ch]) {
                    --ans;
                    break;
                }
            }
            ++ans;
        }
        return ans;
    }
}
