
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;
        const auto n = nums.size();
        for (auto i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ++red;
            } else if (nums[i] == 1) {
                ++white;
            } else {
                ++blue;
            }
        }
        int i = 0;
        while (red > 0) {
            nums[i] = 0;
            ++i;
            --red;
        }
        while (white > 0) {
            nums[i] = 1;
            ++i;
            --white;
        }
        while (blue > 0) {
            nums[i] = 2;
            ++i;
            --blue;
        }
    }
};
