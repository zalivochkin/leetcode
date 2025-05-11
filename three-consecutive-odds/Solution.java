
class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        final int n = arr.length - 2;
        for (var i = 0; i < n; i++) {
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
}
