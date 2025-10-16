
class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        int[] cnt = new int[value];
        for (var num : nums) {
            cnt[(num % value + value) % value] += 1;
        }
        int i = 0;
        while (true) {
            if (cnt[i % value] == 0) {
                return i;
            }
            cnt[i % value] -= 1;
            ++i;
        }
    }
}
