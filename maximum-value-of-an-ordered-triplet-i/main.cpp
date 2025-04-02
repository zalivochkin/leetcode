
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int mx = 0;
        int mx_diff = 0;
        for (const auto num : nums) {
            ans = max(ans, 1LL * mx_diff * num);
            mx = max(mx, num);
            mx_diff = max(mx_diff, mx - num);
        }
        return ans;
    }
};
