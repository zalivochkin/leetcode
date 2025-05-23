
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        for (const auto &num : nums) {
            if (num < pivot) {
                ans.push_back(num);
            }
        }
        for (const auto &num : nums) {
            if (num == pivot) {
                ans.push_back(num);
            }
        }
        for (const auto &num : nums) {
            if (num > pivot) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
