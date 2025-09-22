
class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] cnts = new int[101];
        for (int num : nums) {
            cnts[num] += 1;
        }
        int ans = 0;
        int mx = -1;
        for (int cnt : cnts) {
            if (mx < cnt) {
                mx = cnt;
                ans = cnt;
            } else if (mx == cnt) {
                ans += cnt;
            }
        }
        return ans;
    }
}
