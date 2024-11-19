
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        const auto n = nums.size();
        unordered_map<int, long long> cnts;
        long long sum = 0;
        for (auto i = 0; i < k; ++i) {
            cnts[nums[i]] += 1;
            sum += nums[i];
        }
        long long res = cnts.size() == k ? sum : 0;
        for (auto i = k; i < n; ++i) {
            cnts[nums[i - k]] -= 1;
            if (cnts[nums[i - k]] == 0) {
                cnts.erase(nums[i - k]);
            }
            cnts[nums[i]] += 1;
            sum += nums[i] - nums[i - k];
            if (cnts.size() == k) {
                res = max(res, sum);
            }
        }
        return res;
    }
};
