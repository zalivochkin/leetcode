
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int j1 = -1;
        int j2 = -1;
        int k = -1;
        const auto n = nums.size();
        for (auto i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                k = i;
            }
            if (nums[i] == minK) {
                j1 = i;
            }
            if (nums[i] == maxK) {
                j2 = i;
            }
            ans += max(0, min(j1, j2) - k);
        }
        return ans;
    }
};
