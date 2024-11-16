
class Solution {
public:
    void intToRomanPart(string &res, int num) {
        if (num >= 500 && num < 900) {
            res += "D";
            num -= 500;
        }
        if (num >= 50 && num < 90) {
            res += "L";
            num -= 50;
        }
        if (num >= 5 && num < 9) {
            res += "V";
            num -= 5;
        }
        if (num == 4) {
            res += "IV";
        } else if (num == 9) {
            res += "IX";
        } else if (num == 40) {
            res += "XL";
        } else if (num == 90) {
            res += "XC";
        } else if (num == 400) {
            res += "CD";
        } else if (num == 900) {
            res += "CM";
        } else if (num >= 1000) {
            while (num > 0) {
                res += "M";
                num -= 1000;
            }
        } else if (num >= 100) {
            while (num > 0) {
                res += "C";
                num -= 100;
            }
        } else if (num >= 10) {
            while (num > 0) {
                res += "X";
                num -= 10;
            }
        } else {
            while (num > 0) {
                res += "I";
                --num;
            }
        }
    }

    string intToRoman(int num) {
        stack<int> st;
        while(num > 0) {
            st.push(num % 10);
            num /= 10;
        }
        string res;
        int mul;
        while (!st.empty()) {
            mul = 1;
            for (auto i = 1; i < st.size(); ++i) {
                mul *= 10;
            }
            intToRomanPart(res, st.top() * mul);
            st.pop();
        }
        return res;
    }
};
