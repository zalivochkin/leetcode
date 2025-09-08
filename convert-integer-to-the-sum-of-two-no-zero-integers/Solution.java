
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int a = 1;
        while (true) {
            int b = n - a;
            if (!(a + "" + b).contains("0")) {
                return new int[] {a, b};
            }
            ++a;
        }
    }
}
