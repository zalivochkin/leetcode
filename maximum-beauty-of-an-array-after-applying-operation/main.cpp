
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> cnts;
        for (auto num : nums) {
            cnts[num] += 1;
            cnts[num + k * 2 + 1] -= 1;
        }
        auto res = 0;
        auto summ = 0;
        for (auto [num, cnt] : cnts) {
            summ += cnt;
            res = max(res, summ);
        }
        return res;
    }
};
