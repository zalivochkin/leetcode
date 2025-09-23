
class Solution {
    public int compareVersion(String version1, String version2) {
        final var n = version1.length();
        final var m = version2.length();
        for (int i = 0, j = 0; i < n || j < m; ++i, ++j) {
            int a = 0;
            int b = 0;
            while (i < n && version1.charAt(i) != '.') {
                a = a * 10 + (version1.charAt(i) - '0');
                ++i;
            }
            while (j < m && version2.charAt(j) != '.') {
                b = b * 10 + (version2.charAt(j) - '0');
                ++j;
            }
            if (a != b) {
                return a < b ? -1 : 1;
            }
        }
        return 0;
    }
}
