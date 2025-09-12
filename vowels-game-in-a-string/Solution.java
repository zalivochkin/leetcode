
class Solution {
    public boolean doesAliceWin(String s) {
        final var n = s.length();
        for (var i = 0; i < n; ++i) {
            if ("aeiou".indexOf(s.charAt(i)) != -1) {
                return true;
            }
        }
        return false;
    }
}
