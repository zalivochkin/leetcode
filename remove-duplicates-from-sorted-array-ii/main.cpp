
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        int i = min(2, n);
        for (auto j = 2; j < n; ++j) {
            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};
