
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        while (true) {
            int b = n - a;
            if ((to_string(a) + to_string(b)).find('0') == -1) {
                return {a, b};
            }
            ++a;
        }
    }
};
