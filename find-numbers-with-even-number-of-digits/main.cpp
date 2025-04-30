
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (const auto num : nums) {
            if (to_string(num).size() % 2 == 0) {
                ++ans;
            }
        }
        return ans;
    }
};
