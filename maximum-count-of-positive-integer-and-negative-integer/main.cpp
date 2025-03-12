
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto a = nums.end() - ranges::lower_bound(ranges::views::all(nums), 1);
        auto b = ranges::lower_bound(ranges::views::all(nums), 0) - nums.begin();
        return ranges::max(a, b);
    }
};
