
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (const auto num : nums) {
            int mod = num % 3;
            if (mod) {
                ans += min(mod, 3 - mod);
            }
        }
        return ans;
    }
};
