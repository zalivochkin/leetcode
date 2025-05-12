
import java.util.*;

class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] cnt = new int[10];
        for (var digit : digits) {
            cnt[digit] += 1;
        }
        List<Integer> ans = new ArrayList<>();
        for (int number = 100; number < 1000; number += 2) {
            int[] cnt1 = new int[10];
            for (int number1 = number; number1 > 0; number1 /= 10) {
                cnt1[number1 % 10] += 1;
            }
            boolean ok = true;
            for (int i = 0; i < 10 && ok; ++i) {
                if(cnt[i] < cnt1[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans.add(number);
            }
        }
        return ans.stream().mapToInt(i -> i).toArray();
    }
}
