
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long f0 = 0LL;
        long long f1 = -0x3f3f3f3f;
        for (auto num : nums) {
            long long tmp = f0;
            f0 = max(f0 + num, f1 + (num ^ k));
            f1 = max(f1 + num, tmp + (num ^ k));
        }
        return f0;
    }
};
