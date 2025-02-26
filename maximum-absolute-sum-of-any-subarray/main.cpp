
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0;
        int min_sum = 0;
        int ans = 0;
        for (const auto num : nums) {
            max_sum = max(max_sum, 0) + num;
            min_sum = min(min_sum, 0) + num;
            ans = max({ans, max_sum, abs(min_sum)});
        }
        return ans;
    }
};
