
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        ranges::sort(nums);
        int ans = 1;
        int a = nums[0];
        for (auto num : nums) {
            if (num - a > k) {
                a = num;
                ++ans;
            }
        }
        return ans;
    }
};
