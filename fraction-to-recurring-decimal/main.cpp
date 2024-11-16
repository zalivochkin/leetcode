
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) {
            return "0";
        }
        long long l_numerator = numerator;
        long long l_denominator = denominator;
        string res;
        if (l_numerator < 0 && l_denominator < 0) {
            l_numerator = 0 - l_numerator;
            l_denominator = 0 - l_denominator;
        }
        if (l_numerator < 0) {
            res = "-";
            l_numerator = 0 - l_numerator;
        }
        if (l_denominator < 0) {
            res = "-";
            l_denominator = 0 - l_denominator;
        }
        long long int_part = l_numerator / l_denominator;
        res += to_string(int_part);
        l_numerator = l_numerator % l_denominator;
        if(l_numerator != 0) {
            res += '.';
            unordered_map<long long, int> mp;
            while (l_numerator != 0) {
                if (mp.find(l_numerator) != mp.end()) {
                    int pos = mp[l_numerator];
                    res.insert(pos, "(");
                    res += ')';
                    break;
                } else {
                    mp[l_numerator] = res.length();
                    l_numerator *= 10;
                    int_part = l_numerator / l_denominator;
                    l_numerator = l_numerator % l_denominator;
                    res += to_string(int_part);
                }
            }
        }
        return res;
    }
};
