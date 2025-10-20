
class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ans = 0;
        for (final var operation : operations) {
            if (operation.charAt(1) == '+') {
                ++ans;
            } else {
                --ans;
            }
        }
        return ans;
    }
}
