
import java.util.*;

class Solution {
    public long countGoodIntegers(int n, int k) {
        long[] fac = new long[n + 1];
        fac[0] = 1;
        for (var i = 1; i <= n; i++) {
            fac[i] = fac[i - 1] * i;
        }

        long ans = 0;
        Set<String> vis = new HashSet<>();
        int base = (int) Math.pow(10, (n - 1) / 2);
        int[] cnts = new int[10];
        for (var i = base; i < base * 10; i++) {
            String s = String.valueOf(i);
            StringBuilder sb = new StringBuilder(s).reverse();
            s += sb.substring(n % 2);
            if (Long.parseLong(s) % k != 0) {
                continue;
            }

            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            String t = new String(arr);
            if (vis.contains(t)) {
                continue;
            }
            vis.add(t);
            Arrays.fill(cnts, 0);
            for (var ch : arr) {
                cnts[ch - '0']++;
            }

            long res = (n - cnts[0]) * fac[n - 1];
            for (var cnt : cnts) {
                res /= fac[cnt];
            }
            ans += res;
        }

        return ans;
    }
}
