
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        ranges::sort(nums);
        const int mod = 1e9 + 7;
        const auto n = nums.size();
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for (auto i = 1; i <= n; ++i) {
            f[i] = (f[i - 1] * 2) % mod;
        }
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            if (nums[i] * 2L > target) {
                break;
            }
            int j = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin() - 1;
            ans = (ans + f[j - i]) % mod;
        }
        return ans;
    }
};
