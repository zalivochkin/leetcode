
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        const auto n = nums.size();
        int ans = 1;
        for (auto i = 1, t = 1; i < n; ++i) {
            if (nums[i - 1] < nums[i]) {
                ++t;
                ans = max(ans, t);
            } else {
                t = 1;
            }
        }
        for (auto i = 1, t = 1; i < n; ++i) {
            if (nums[i - 1] > nums[i]) {
                ++t;
                ans = max(ans, t);
            } else {
                t = 1;
            }
        }
        return ans;
    }
};
