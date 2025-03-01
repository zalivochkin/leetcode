
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        const auto n = nums.size();
        for (auto i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
        vector<int> ans(n);
        int i = 0;
        for (const auto num : nums) {
            if (num) {
                ans[i] = num;
                i++;
            }
        }
        return ans;
    }
};
