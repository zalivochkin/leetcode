
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        int hr_bits;
        int mn_bits;
        vector<string> res;
        for (auto hr = 0; hr < 12; ++hr) {
            hr_bits = __builtin_popcount(hr);
            if (hr_bits <= turnedOn) {
                for (auto mn = 0; mn < 60; ++mn) {
                    mn_bits = __builtin_popcount(mn);
                    if (hr_bits + mn_bits == turnedOn) {
                        string mn_s = to_string(mn);
                        if (mn_s.size() < 2) {
                            mn_s = "0" + mn_s;
                        }
                        res.push_back(to_string(hr) + ":" + mn_s);
                    }
                }
            }
        }
        return res;
    }
};
