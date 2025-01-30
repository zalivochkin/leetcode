
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const auto n = nums.size();
        int dp = nums[0];
        int res = nums[0];
        for (auto i = 1; i < n; ++i) {
            dp = max(dp, 0) + nums[i];
            res = max(res, dp);
        }
        return res;
    }
};
