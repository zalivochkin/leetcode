
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int x = 0;
        for (const auto num : nums) {
            x = (x << 1 | num) % 5;
            ans.push_back(x == 0);
        }
        return ans;
    }
};
