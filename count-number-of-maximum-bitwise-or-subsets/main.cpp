
class Solution {
public:
    void helper(const vector<int> &nums, const size_t n, int start_indx, int cur_or, int max_or, int &res) {
        if (cur_or == max_or) {
            ++res;
        }
        for (auto i = start_indx; i < n; ++i) {
            helper(nums, n, i + 1, cur_or | nums[i], max_or, res);
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        const auto n = nums.size();
        int max_or = accumulate(nums.begin(), nums.end(), 0, [](const int a, const int b){ return a | b; });
        int res = 0;
        helper(nums, n, 0, 0, max_or, res);
        return res;
    }
};
