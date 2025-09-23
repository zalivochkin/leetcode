
class Solution {
public:
    int compareVersion(string version1, string version2) {
        const auto n = version1.size();
        const auto m = version2.size();
        for (int i = 0, j = 0; i < n || j < m; ++i, ++j) {
            int a = 0;
            int b = 0;
            while (i < n && version1[i] != '.') {
                a = a * 10 + (version1[i] - '0');
                ++i;
            }
            while (j < m && version2[j] != '.') {
                b = b * 10 + (version2[j] - '0');
                ++j;
            }
            if (a != b) {
                return a < b ? -1 : 1;
            }
        }
        return 0;
    }
};
