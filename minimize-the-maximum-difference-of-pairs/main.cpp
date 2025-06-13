
class Solution {
public:
    bool check(vector<int>& nums, int n, int diff, int p) {
        int cnt = 0;
        for (auto i = 0; i < n - 1; ++i) {
            if (nums[i + 1] - nums[i] <= diff) {
                ++cnt;
                ++i;
            }
        }
        return cnt >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        ranges::sort(nums);
        const auto n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0] + 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(nums, n, mid, p)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
