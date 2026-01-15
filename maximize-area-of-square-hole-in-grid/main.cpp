
class Solution {
public:
    int f(vector<int>& nums) {
        int ans = 1;
        int cnt = 1;
        ranges::sort(nums);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ans = max(ans, ++cnt);
            } else {
                cnt = 1;
            }
        }
        return ans + 1;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int x = min(f(hBars), f(vBars));
        return x * x;
    }
};
