
class Solution {
public:
    bool check(vector<int>& nums, int k, const int start_indx) {
        const auto n = nums.size();
        for (auto i = start_indx + 1; i < start_indx + k; ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                return false;
            }
        }
        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        const auto n = nums.size();
        vector<int> res(n - k + 1);
        for (auto i = 0; i <= n - k; ++i) {
            if (check(nums, k, i)) {
                res[i] = nums[i + k - 1];
            } else {
                res[i] = -1;
            }
        }
        return res;
    }
};
