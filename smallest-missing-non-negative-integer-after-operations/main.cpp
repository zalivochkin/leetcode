
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> cnt(value, 0);
        for (auto num : nums) {
            cnt[(num % value + value) % value] += 1;
        }
        int i = 0;
        while (true) {
            if (cnt[i % value] == 0) {
                return i;
            }
            cnt[i % value] -= 1;
            ++i;
        }
    }
};
