
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        ranges::sort(nums);
        vector<vector<int>> ans;
        const auto n = nums.size();
        for (int i = 0; i < n; i += 3) {
            vector<int> t = {nums[i], nums[i + 1], nums[i + 2]};
            if (t[2] - t[0] > k) {
                return {};
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};
