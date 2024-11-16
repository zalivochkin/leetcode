
class Solution {
public:
    long long countQuadruplets(vector<int> &nums) {
        long long res = 0;
        auto n = nums.size();
        vector<int> temp(n, 0);
        int prev;
        for (auto i = 0; i < n; ++i) {
            prev = 0;
            for (auto j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    res += temp[j];
                    ++prev;
                } else {
                    temp[j] += prev;
                }
            }
        }
        return res;
    }
};
