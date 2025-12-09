
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> right;
        for (const auto num : nums) {
            right[num]++;
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        unordered_map<int, int> left;
        for (const auto num : nums) {
            right[num] -= 1;
            ans = (ans + 1LL * left[num * 2] * right[num * 2] % mod) % mod;
            left[num] += 1;
        }
        return (int) ans;
    }
};
