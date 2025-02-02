
class Solution {
public:
    bool check(vector<int>& nums) {
        const auto n = nums.size();
        int cnt = 0;
        for (auto i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                ++cnt;
                if (cnt > 1) {
                    break;
                }
            }
        }
        return cnt == 0 || cnt == 1 && nums[0] >= nums[n - 1];
    }
};
