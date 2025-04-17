
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        const auto n = nums.size();
        for (auto i = 0; i < n; i++) {
            for (auto j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};
