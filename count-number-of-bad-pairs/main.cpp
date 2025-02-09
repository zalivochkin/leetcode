
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        const auto n = nums.size();
        unordered_map<int, int> cnts;
        long long cnt = 0;
        for (auto i = 0; i < n; ++i) {
            cnt += i - cnts[i - nums[i]];
            cnts[i - nums[i]] += 1;
        }
        return cnt;
    }
};
