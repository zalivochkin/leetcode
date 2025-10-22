
class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        Map<Integer, Integer> cnt = new HashMap<>();
        TreeMap<Integer, Integer> d = new TreeMap<>();
        for (final var num : nums) {
            cnt.merge(num, 1, Integer::sum);
            d.putIfAbsent(num, 0);
            d.merge(num - k, 1, Integer::sum);
            d.merge(num + k + 1, -1, Integer::sum);
        }
        int ans = 0;
        int summ = 0;
        for (var e : d.entrySet()) {
            int x = e.getKey();
            int t = e.getValue();
            summ += t;
            ans = Math.max(ans, Math.min(summ, cnt.getOrDefault(x, 0) + numOperations));
        }
        return ans;
    }
}
