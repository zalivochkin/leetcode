
class Solution {
public:
    string clearDigits(string s) {
        string stk;
        for (const auto ch : s) {
            if (isdigit(ch)) {
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }
        return stk;
    }
};
