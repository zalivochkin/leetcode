
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        auto left = 1;
        auto right = *max_element(nums.begin(), nums.end());
        auto mid = left;
        long long cnt;
        while (left < right) {
            mid = left + (right - left) / 2;
            cnt = accumulate(nums.begin(), nums.end(), 0, [mid](int cur_sum, int num) -> int {
                return cur_sum + (num - 1) / mid;
            });
            if (cnt <= maxOperations) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
