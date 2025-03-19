
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const auto n = nums.size();
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                if (i + 2 >= n) {
                    return -1;
                }
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ++ans;
            }
        }
        return ans;
    }
};
