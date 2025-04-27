
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        const auto n = nums.size();
        int res = 0;
        for (auto i = 2; i < n; ++i) {
            if ((nums[i - 2] + nums[i]) * 2 == nums[i - 1]) {
                ++res;
            }
        }
        return res;
    }
};
