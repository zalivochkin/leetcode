
class Solution {
public:
    string baseNeg2(int n) {
        string res;
        while (n != 0) {
            if (n % 2 != 0) {
                res += "1";
                n = (n - 1) / -2;
            } else {
                res += "0";
                n = n / -2;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
