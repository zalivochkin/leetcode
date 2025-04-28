
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        long long s = 0;
        const auto n = nums.size();
        for (auto i = 0, j = 0; i < n; ++i) {
            s += nums[i];
            while (s * (i - j + 1) >= k) {
                s -= nums[j];
                ++j;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};
