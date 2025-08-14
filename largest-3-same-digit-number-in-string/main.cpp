
class Solution {
public:
    string largestGoodInteger(string num) {
        int cur_num = num[0] - '0';
        int cnt = 0;
        int max_num = -1;
        for (const auto ch : num) {
            if (ch - '0' == cur_num) {
               ++cnt;
               if (cnt == 3) {
                   max_num = max(max_num, cur_num);
               }
            } else {
                cur_num = ch - '0';
                cnt = 1;
            }
        }
        if (max_num > 0) {
            return to_string(max_num * 100 + max_num * 10 + max_num);
        } else if (max_num == 0) {
            return "000";
        }
        return "";
    }
};
