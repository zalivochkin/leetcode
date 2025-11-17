
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int j = -(k + 1);
        const auto n = nums.size();
        for (auto i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                if (i - j - 1 < k) {
                    return false;
                }
                j = i;
            }
        }
        return true;
    }
};
