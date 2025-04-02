
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        const auto n = nums.size();
        for (auto i = 0; i < n; ++i) {
            if (mx < i) {
                return false;
            }
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};
