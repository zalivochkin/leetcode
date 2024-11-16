
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        int a_cntr = 0;
        int b_cntr = 0;
        int c_cntr = 0;
        while (a > 0 || b > 0 || c > 0) {
            if (a >= b && a >= c && a_cntr < 2) {
                res += 'a';
                --a;
                ++a_cntr;
                b_cntr = 0;
                c_cntr = 0;
            } else if (b >= a && b >= c && b_cntr < 2) {
                res += 'b';
                --b;
                ++b_cntr;
                a_cntr = 0;
                c_cntr = 0;
            } else if (c >= a && c >= b && c_cntr < 2) {
                res += 'c';
                --c;
                ++c_cntr;
                a_cntr = 0;
                b_cntr = 0;
            } else {
                if (a > 0 && a_cntr < 2) {
                    res += 'a';
                    --a;
                    ++a_cntr;
                    b_cntr = 0;
                    c_cntr = 0;
                } else if (b > 0 && b_cntr < 2) {
                    res += 'b';
                    --b;
                    ++b_cntr;
                    a_cntr = 0;
                    c_cntr = 0;
                } else if (c > 0 && c_cntr < 2) {
                    res += 'c';
                    --c;
                    ++c_cntr;
                    a_cntr = 0;
                    b_cntr = 0;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
