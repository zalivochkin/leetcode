
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(100005);
        int res = 0;
        int x;
        for (auto num: nums) {
            x = sqrt(num);
            if (x * x == num) {
                dp[num] = dp[x] + 1;
                res = max(res, dp[num]);
            } else {
                dp[num] = 1;
            }
        }
        return res > 1 ? res : -1;
    }
};
