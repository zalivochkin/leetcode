
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *ranges::max_element(nums);
        int ans = 0;
        int cnt = 0;
        for (auto num : nums) {
            if (num == mx) {
                ++cnt;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
