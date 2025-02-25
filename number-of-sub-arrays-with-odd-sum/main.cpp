
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int cnt[2] = {1, 0};
        long long ans = 0;
        long long summ = 0;
        for (const auto num : arr) {
            summ += num;
            ans += cnt[(summ & 1) ^ 1];
            ans %= mod;
            cnt[summ & 1] += 1;
        }
        return ans;
    }
};
