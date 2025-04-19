
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        return lb(nums, upper + 1) - lb(nums, lower);
    }

private:
    long long lb(vector<int> &nums, int value) {
        int left = 0;
        int right = nums.size() - 1;
        int sum;
        long long res = 0;
        while (left < right) {
            sum = nums[left] + nums[right];
            if (sum < value) {
                res += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};
