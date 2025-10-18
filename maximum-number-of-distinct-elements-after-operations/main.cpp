
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int ans = 0;
        int occupied = numeric_limits<int>::min();
        ranges::sort(nums);
        for (const int num : nums) {
            if (occupied < num + k) {
                occupied = max(occupied + 1, num - k);
                ++ans;
            }
        }
        return ans;
    }
};
