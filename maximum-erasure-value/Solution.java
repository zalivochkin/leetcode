
class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        Set<Integer> vis = new HashSet<>();
        int ans = 0;
        int summ = 0;
        int i = 0;
        for (var num : nums) {
            while (vis.contains(num)) {
                summ -= nums[i];
                vis.remove(nums[i]);
                ++i;
            }
            vis.add(num);
            summ += num;
            ans = Math.max(ans, summ);
        }
        return ans;
    }
}
