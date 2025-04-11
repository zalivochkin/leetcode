
class Solution {
    int check(int num) {
        String s = "" + num;
        int n = s.length();
        if (n % 2 == 1) {
            return 0;
        }
        int sum1 = 0;
        for (int i = 0; i < n / 2; ++i) {
            sum1 += s.charAt(i) - '0';
        }
        int sum2 = 0;
        for (int i = n / 2; i < n; ++i) {
            sum2 += s.charAt(i) - '0';
        }
        return sum1 == sum2 ? 1 : 0;
    }

    public int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (var i = low; i <= high; ++i) {
            res += check(i);
        } 
        return res;
    }
}
