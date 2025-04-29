
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *ranges::max_element(nums);
        const auto n = nums.size();
        long long ans = 0;
        int cnt = 0;
        int j = 0;
        for (auto num : nums) {
            while (j < n && cnt < k) {
                if (nums[j] == mx) {
                    ++cnt;
                }
                ++j;
            }
            if (cnt < k) {
                break;
            }
            ans += n - j + 1;
            if (num == mx) {
                --cnt;
            }
        }
        return ans;
    }
};
