
class Solution {
public:
    inline bool isDistsCountLessThan(const vector<int>& nums, int X, int k) {
        auto n = nums.size();
        auto cntr = 0;
        auto fast_indx = 0;
        for (auto slow_indx = 0; slow_indx < n; ++slow_indx) {
            while (fast_indx < n && nums[fast_indx] - nums[slow_indx] <= X) {
                ++fast_indx;
            }
            cntr += fast_indx - slow_indx - 1;
            if (cntr >= k) {
                return false;
            }
        }
        return cntr < k;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        auto n = nums.size();
        sort(nums.begin(), nums.end());
        int lft = 0;
        auto rght = nums[n - 1] - nums[0];
        while (lft < rght) {
            auto mid = lft + (rght - lft) / 2;
            if (isDistsCountLessThan(nums, mid, k)) {
                lft = mid + 1;
            }else {
                rght = mid;
            }
        }
        return lft;
    }
};
