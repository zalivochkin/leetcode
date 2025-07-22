
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> vis;
        int ans = 0;
        int summ = 0;
        int i = 0;
        for (auto num : nums) {
            while (vis.contains(num)) {
                summ -= nums[i];
                vis.erase(nums[i]);
                ++i;
            }
            vis.insert(num);
            summ += num;
            ans = max(ans, summ);
        }
        return ans;
    }
};
