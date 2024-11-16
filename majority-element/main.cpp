
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        auto lim = nums.size() / 2;
        unordered_map<int, int> freq;
        for (auto num : nums) {
            freq[num] += 1;
        }
        for (auto fr : freq) {
            if (fr.second > lim) {
                return fr.first;
            }
        }
        return -1;
    }
};
