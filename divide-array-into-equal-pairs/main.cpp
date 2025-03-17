
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto num : nums) {
            mp[num] += 1;
        }
        for (auto [_, cnt] : mp) {
            if (cnt % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};
