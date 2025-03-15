
class Solution {
public:
    static bool check(vector<int>& nums, int k, int x) {
        const auto n = nums.size();
        int cnt = 0;
        int j = -2;
        for (auto i = 0; i < n; ++i) {
            if (nums[i] > x || i == j + 1) {
                continue;
            }
            ++cnt;
            j = i;
        }
        return cnt >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = 0;
        int right = *ranges::max_element(ranges::views::all(nums));
        while (left < right) {
            int mid = midpoint(left, right);
            if (check(nums, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
