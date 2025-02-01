
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        const auto n = nums.size();
        for (auto i = 1; i < n; ++i) {
            if (nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) {
                return false;
            }
            if (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};
