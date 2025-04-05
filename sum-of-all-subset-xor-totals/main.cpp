
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        const auto n = nums.size();
        for (auto i = 0; i < 1 << n; ++i) {
            int xor_sum = 0;
            for (auto j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    xor_sum ^= nums[j];
                }
            }
            sum += xor_sum;
        }
        return sum;
    }
};
