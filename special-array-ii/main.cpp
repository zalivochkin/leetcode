
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        const auto n = nums.size();
        const auto m = queries.size();
        vector<int> prefix(n);
        prefix[0] = 0;
        for (auto i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
                ++prefix[i];
            }
        }
        vector<bool> res(m);
        for (auto i = 0; i < m; ++i) {
            res[i] = prefix[queries[i][1]] - (queries[i][0] > 0 ? prefix[queries[i][0]] : 0) == 0;
        }
        return res;
    }
};
