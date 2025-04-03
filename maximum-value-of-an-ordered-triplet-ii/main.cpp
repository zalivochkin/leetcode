
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const auto n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        for (auto i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = max(suffix[i + 1], nums[i]);
        }
        long long ans = 0;
        for (auto i = 1; i < n - 1; i++) {
            ans = max(ans, ((long long)prefix[i - 1] - nums[i]) * suffix[i + 1]);
        }
        return ans;
    }
};
