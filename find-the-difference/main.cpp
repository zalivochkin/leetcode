
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> oq('z' + 1, 0);
        for (auto ch : s) {
            oq[ch] += 1;
        }
        for (auto ch : t) {
            oq[ch] -= 1;
            if (oq[ch] < 0) {
                return ch;
            }
        }
        return 0;
    }
};
