
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stk;
        for (int num : nums) {
            stk.push_back(num);
            while (stk.size() > 1) {
                num = stk.back();
                int y = stk[stk.size() - 2];
                int g = __gcd(num, y);
                if (g == 1) {
                    break;
                }
                stk.pop_back();
                stk.back() = 1LL * num * y / g;
            }
        }
        return stk;
    }
};
