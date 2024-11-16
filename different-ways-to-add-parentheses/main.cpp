
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        auto n = expression.size();
        vector<int> res;
        if (n == 0) {
            return res;
        }
        if (n == 1) {
            res.push_back(stoi(expression));
            return res;
        }
        if (n == 2 && isdigit(expression[0])) {
            res.push_back(stoi(expression));
            return res;
        }
        char ch;
        vector<int> left_ways, right_ways;
        for (auto i = 0; i < n; ++i) {
            ch = expression[i];
            if (isdigit(ch)) {
                continue;
            }
            left_ways = diffWaysToCompute(expression.substr(0, i));
            right_ways = diffWaysToCompute(expression.substr(i + 1));
            for (auto arg1 : left_ways) {
                for (auto arg2 : right_ways) {
                    switch (ch) {
                        case '+' : res.push_back(arg1 + arg2); break;
                        case '-' : res.push_back(arg1 - arg2); break;
                        case '*' : res.push_back(arg1 * arg2); break;
                    }
                }
            }
        }
        return res;
    }
};
