
class Solution {
    public int minOperations(int[] nums, int k) {
        int summ = 0;
        for (var num : nums)
          summ += num;
        return summ % k;
    }
}
