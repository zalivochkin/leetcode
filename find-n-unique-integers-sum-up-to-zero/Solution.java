
class Solution {
    public int[] sumZero(int n) {
        var ans = new int[n];
        for (var i = 1; i < n; ++i) {
            ans[i] = i;
        }
        ans[0] = -(n * (n - 1) / 2);
        return ans;
    }
}
