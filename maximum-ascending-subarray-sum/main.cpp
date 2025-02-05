
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        const auto n = nums.size();
        int curr_sum = nums[0];
        int max_sum = curr_sum;
        for (auto i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                curr_sum += nums[i];
                max_sum = max(max_sum, curr_sum);
            } else {
                curr_sum = nums[i];
            }
        }
        return max_sum;
    }
};
