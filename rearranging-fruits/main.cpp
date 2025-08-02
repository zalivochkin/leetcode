
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        const auto n = basket1.size();
        unordered_map<int, int> cnt;
        for (auto i = 0; i < n; ++i) {
            cnt[basket1[i]] += 1;
            cnt[basket2[i]] -= 1;
        }
        int mi = 1 << 30;
        vector<int> nums;
        for (auto [x, v] : cnt) {
            if (v % 2) {
                return -1;
            }
            for (int i = abs(v) / 2; i; --i) {
                nums.push_back(x);
            }
            mi = min(mi, x);
        }
        ranges::sort(nums);
        const auto m = nums.size();
        long long ans = 0;
        for (auto i = 0; i < m / 2; ++i) {
            ans += min(nums[i], mi * 2);
        }
        return ans;
    }
};
