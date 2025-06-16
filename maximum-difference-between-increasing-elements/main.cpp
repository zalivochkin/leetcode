
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mi = numeric_limits<int>::max();
        int ans = -1;
        for (auto x : nums) {
            if (x > mi) {
                ans = max(ans, x - mi);
            } else {
                mi = x;
            }
        }
        return ans;
    }
};
