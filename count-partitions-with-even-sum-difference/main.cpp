
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int left_sum = nums[0];
        int right_sum = accumulate(nums.begin() + 1, nums.end(), 0);
        int ans = ((left_sum - right_sum) % 2) == 0;
        const auto n = nums.size();
        for (int i = 1; i < n - 1; ++i) {
            left_sum += nums[i];
            right_sum -= nums[i];
            if (((left_sum - right_sum) % 2) == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
