
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        const auto n = nums.size();
        int ans = 0;
        int mask = 0;
        for (auto lft = 0, rght = 0; rght < n; ++rght) {
            while (mask & nums[rght]) {
                mask ^= nums[lft];
                ++lft;
            }
            mask |= nums[rght];
            ans = max(ans, rght - lft + 1);
        }
        return ans;
    }
};
