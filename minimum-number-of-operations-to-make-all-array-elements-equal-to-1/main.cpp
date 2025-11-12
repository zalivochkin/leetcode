
class Solution {
public:
    int minOperations(vector<int>& nums) {
        const auto n = nums.size();
        int cnt = 0;
        for (int num : nums) {
            if (num == 1) {
                ++cnt;
            }
        }
        if (cnt) {
            return n - cnt;
        }
        auto mi = n + 1;
        for (size_t i = 0; i < n; ++i) {
            size_t g = 0;
            for (auto j = i; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    mi = min(mi, j - i + 1);
                }
            }
        }
        return mi > n ? -1 : n - 1 + mi - 1;
    }
};
