
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        int total_rem = total_sum % p;
        if (total_rem == 0) {
            return 0;
        }
        unordered_map<int, int> mp;
        auto n = nums.size();
        int res = n;
        total_sum = 0;
        for (auto i = 0; i < n; ++i) {
            total_sum += nums[i];
            int rem = total_sum % p;
            int target_rem = (rem - total_rem + p) % p;
            if (target_rem == 0) {
                res = min(res, i + 1);
            }
            if (mp.contains(target_rem)) {
                res = min(res, i - mp[target_rem]);
            }
            mp[rem] = i;
        }
        if (res == n) {
            return -1;
        }
        return res;
    }
};
