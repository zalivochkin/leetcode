
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        const auto n = nums.size();
        unordered_map<int, int> cnts;
        for (auto i = 1; i < n; ++i) {
            for (auto j = 0; j < i; ++j) {
                cnts[nums[i] * nums[j]] += 1;
            }
        }
        int ans = 0;
        for (auto [_, cnt] : cnts) {
            ans += cnt * (cnt - 1) / 2;
        }
        return ans << 3;
    }
};
