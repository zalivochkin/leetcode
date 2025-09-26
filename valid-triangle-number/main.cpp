
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0;
        const auto n = static_cast<int>(nums.size()) - 2;
        const auto m = n + 1;
        for (auto i = 0; i < n; ++i) {
            for (auto j = i + 1; j < m; ++j) {
                int k = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin() - 1;
                ans += k - j;
            }
        }
        return ans;
    }
};
