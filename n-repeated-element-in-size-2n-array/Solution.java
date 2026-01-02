
class Solution {
    public int repeatedNTimes(int[] nums) {
        Set<Integer> s = new HashSet<>(nums.length / 2 + 1);
        int i = 0;
        while (true) {
            if (!s.add(nums[i])) {
                return nums[i];
            }
            ++i;
        }
    }
}
