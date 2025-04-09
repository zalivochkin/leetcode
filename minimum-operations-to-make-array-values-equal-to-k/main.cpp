
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> has_x;
        int x_min = numeric_limits<int>::max();
        for (const auto x: nums) {
            has_x.insert(x);
            x_min = min(x, x_min);
        }
        if (x_min < k) {
            return -1;
        }
        return (x_min == k) ? has_x.size() - 1 : has_x.size();
    }
};
