
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        const auto n = nums.size();
        for (int i = 1, j = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] > nums[j] && nums[i] > nums[i + 1]) {
                ++ans;
            }
            if (nums[i] < nums[j] && nums[i] < nums[i + 1]) {
                ++ans;
            }
            j = i;
        }
        return ans;
    }
};
