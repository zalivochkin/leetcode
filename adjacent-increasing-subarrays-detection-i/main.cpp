
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int mx = 0;
        int pre = 0;
        int cur = 0;
        const auto n = nums.size();
        for (auto i = 0; i < n; ++i) {
            ++cur;
            if (i == n - 1 || nums[i] >= nums[i + 1]) {
                mx = max({mx, cur / 2, min(pre, cur)});
                pre = cur;
                cur = 0;
            }
        }
        return mx >= k;
    }
};
