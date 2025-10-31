
class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int[] ans = new int[2];
        int[] cnt = new int[100];
        int k = 0;
        for (int num : nums) {
            cnt[num] += 1;
            if (cnt[num] == 2) {
                ans[k] = num;
                ++k;
            }
        }
        return ans;
    }
}
