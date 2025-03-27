
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int x = 0;
        int cnt = 0;
        unordered_map<int, int> freq;
        for (const auto num : nums) {
            ++freq[num];
            if (freq[num] > cnt) {
                cnt = freq[num];
                x = num;
            }
        }
        int cur = 0;
        const auto n = nums.size();
        for (auto i = 1; i <= n; ++i) {
            if (nums[i - 1] == x) {
                ++cur;
                if (cur * 2 > i && (cnt - cur) * 2 > nums.size() - i) {
                    return i - 1;
                }
            }
        }
        return -1;
    }
};
