
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        const auto n = nums.size();
        for (auto i = 0; i < n; ++i) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};
