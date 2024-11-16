
class Solution {
public:
    inline int check(int num) const {
        int n = 0;
        auto tmp_num = num;
        while(tmp_num > 0){
            tmp_num /= 10;
            ++n;
        }
        if (n % 2 != 0) {
            return 0;
        }
        string num_str = to_string(num);
        n /= 2;
        int sum1 = 0;
        int sum2 = 0;
        for (auto i = 0; i < n; ++i) {
            sum1 += num_str[i] - '0';
            sum2 += num_str[i + n] - '0';
        }
        return sum1 == sum2;
    }

    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (auto i = low; i <= high; ++i) {
            res += check(i);
        } 
        return res;
    }
};
