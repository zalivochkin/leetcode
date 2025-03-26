
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const auto n = grid.size();
        const auto m = grid[0].size();
        int mod = grid[0][0] % x;
        vector<int> nums(n * m);
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j] % x != mod) {
                    return -1;
                }
                nums[i * m + j] = grid[i][j];
            }
        }
        sort(nums.begin(), nums.begin() + n * m);
        int mid = nums[n * m / 2];
        int ans = 0;
        for (const auto num : nums) {
            ans += abs(num - mid) / x;
        }
        return ans;
    }
};
