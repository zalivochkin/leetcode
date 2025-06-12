
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = abs(nums.front() - nums.back());
        const auto n = nums.size();
        for (auto i = 0; i + 1 < n; ++i) {
            ans = max(ans, abs(nums[i] - nums[i + 1]));
        }
        return ans;
    }
};
