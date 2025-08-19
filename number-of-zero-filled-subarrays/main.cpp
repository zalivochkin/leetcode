
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int cnt = 0;
        for (const auto num : nums) {
            if (num == 0) {
                ++cnt;
            } else {
                cnt = 0;
            } 
            ans += cnt;
        }
        return ans;
    }
};
