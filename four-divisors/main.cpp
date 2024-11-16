
class Solution {
public:
    int calcDivisors(int num, vector<int>& res) {
        int cnt = -1;
        for (auto i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                if (cnt > 2) {
                    return -1;
                }
                if (i == num / i) {
                    res[++cnt] = i;
                } else {
                    res[++cnt] = i;
                    res[++cnt] = num / i;
                }
            }
        }
        return cnt + 1;
    }

    int sumFourDivisors(vector<int>& nums) {
        vector<int> divisors(4);
        int res = 0;
        for (auto num : nums) {
            if (calcDivisors(num, divisors) == 4) {
                res = accumulate(divisors.begin(), divisors.end(), res);
            }
        }
        return res;
    }
};
