
class Solution {
  public int maxFreqSum(String s) {
    var count = new int['z' + 1];
    int maxVowel = 0;
    int maxConsonant = 0;
    for (final var ch : s.toCharArray()) {
      ++count[ch];
    }
    for (final var ch : s.toCharArray()) {
      if (isVowel(ch)) {
        maxVowel = Math.max(maxVowel, count[ch]);
      } else {
        maxConsonant = Math.max(maxConsonant, count[ch]);
      }
    }
    return maxVowel + maxConsonant;
  }

  private boolean isVowel(char ch) {
    return "aeiou".indexOf(ch) != -1;
  }
}
