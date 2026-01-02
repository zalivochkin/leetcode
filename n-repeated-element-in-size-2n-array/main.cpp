
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        int i = 0;
        while (true) {
            if (s.count(nums[i])) {
                return nums[i];
            }
            s.insert(nums[i]);
            ++i;
        }
    }
};
