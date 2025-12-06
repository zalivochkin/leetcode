
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        multiset<int> sl;
        const auto n = nums.size();
        vector<int> dp1(n + 1, 0);
        vector<int> dp2(n + 1, 0);
        dp1[0] = 1;
        dp2[0] = 1;
        int l = 1;
        for (auto r = 1; r <= n; ++r) {
            int x = nums[r - 1];
            sl.insert(x);
            while (*sl.rbegin() - *sl.begin() > k) {
                sl.erase(sl.find(nums[l - 1]));
                ++l;
            }
            dp1[r] = (dp2[r - 1] - (l >= 2 ? dp2[l - 2] : 0) + mod) % mod;
            dp2[r] = (dp2[r - 1] + dp1[r]) % mod;
        }
        return dp1[n];
    }
};
