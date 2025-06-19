
class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int ans = 1;
        int a = nums[0];
        for (var num : nums) {
            if (num - a > k) {
                a = num;
                ++ans;
            }
        }
        return ans;
    }
}
