
class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> ans = new ArrayList<>();
        int x = 0;
        for (final var num : nums) {
            x = (x << 1 | num) % 5;
            ans.add(x == 0);
        }
        return ans;
    }
}
