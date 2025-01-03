
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        const auto n = nums.size();
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        long long cur_sum = 0;
        int res = 0;
        for (auto i = 0; i + 1 < n; ++i) {
            cur_sum += nums[i];
            if (cur_sum >= total_sum - cur_sum) {
                ++res;
            }
        }
        return res;
    }
};
