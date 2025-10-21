
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        map<int, int> d;
        for (int num : nums) {
            cnt[num]++;
            d[num];
            d[num - k]++;
            d[num + k + 1]--;
        }
        int ans = 0;
        int summ = 0;
        for (const auto [x, t] : d) {
            summ += t;
            ans = max(ans, min(summ, cnt[x] + numOperations));
        }
        return ans;
    }
};
