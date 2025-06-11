
import java.util.*;

class Solution {
    public int maxDifference(String s, int k) {
        int ans = Integer.MIN_VALUE;
        for (char[] pair : getPermutations()) {
            char a = pair[0];
            char b = pair[1];
            int[][] minDiff = new int[2][2];
            for (int[] row : minDiff) {
                Arrays.fill(row, Integer.MAX_VALUE / 2);
            }
            List<Integer> prefixA = new ArrayList<>();
            List<Integer> prefixB = new ArrayList<>();
            prefixA.add(0);
            prefixB.add(0);
            int l = 0;
            for (int r = 0; r < s.length(); ++r) {
                prefixA.add(prefixA.get(r) + (s.charAt(r) == a ? 1 : 0));
                prefixB.add(prefixB.get(r) + (s.charAt(r) == b ? 1 : 0));
                while (r - l + 1 >= k && prefixA.get(l) < prefixA.get(r + 1) && prefixB.get(l) < prefixB.get(r + 1)) {
                    int paMod = prefixA.get(l) % 2;
                    int pbMod = prefixB.get(l) % 2;
                    minDiff[paMod][pbMod] = Math.min(minDiff[paMod][pbMod], prefixA.get(l) - prefixB.get(l));
                    ++l;
                }
                int pa = prefixA.get(r + 1);
                int pb = prefixB.get(r + 1);
                int paMod = pa % 2;
                int pbMod = pb % 2;
                int candidate = (pa - pb) - minDiff[1 - paMod][pbMod];
                ans = Math.max(ans, candidate);
            }
        }
        return ans;
    }

    private List<char[]> getPermutations() {
        List<char[]> permutations = new ArrayList<>();
        for (char a : "01234".toCharArray()) {
            for (char b : "01234".toCharArray()) {
                if (a != b) {
                    permutations.add(new char[]{a, b});
                }
            }
        }
        return permutations;
    }
}
