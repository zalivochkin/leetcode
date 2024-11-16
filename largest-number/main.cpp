
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto n = nums.size();
        vector<string> numss(n);
        for (auto i = 0; i < n; ++i) {
            numss[i] = to_string(nums[i]);
        }
        sort(numss.begin(), numss.end(), [](const string &a, const string & b) -> bool {
            return (a + b) > (b + a);
        });
        if (numss[0] == "0") {
            return "0";
        }
        string res;
        for (const auto &num_s : numss) {
            res += num_s;
        }
        return res;
    }
};
