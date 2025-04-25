
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        const auto n = nums.size();
        vector<bool> is_good(n, false);
        for (auto i = 0; i < n; ++i) {
            if (nums[i] % modulo == k) {
                is_good[i] = true;
            }
        }
        unordered_map<int, int> cnts;
        cnts[0] = 1;
        long long ans = 0;
        int s = 0;
        for (auto x : is_good) {
            if (x) {
                s += 1;
            }
            ans += cnts[(s - k + modulo) % modulo];
            cnts[s % modulo] += 1;
        }
        return ans;
    }
};
