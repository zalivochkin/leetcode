
class Solution {
    public int[] avoidFlood(int[] rains) {
        final var n = rains.length;
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        TreeSet<Integer> sunny = new TreeSet<>();
        Map<Integer, Integer> rainy = new HashMap<>();
        for (var i = 0; i < n; ++i) {
            var rain = rains[i];
            if (rain > 0) {
                if (rainy.containsKey(rain)) {
                    Integer t = sunny.higher(rainy.get(rain));
                    if (t == null) {
                        return new int[0];
                    }
                    ans[t] = rain;
                    sunny.remove(t);
                }
                rainy.put(rain, i);
            } else {
                sunny.add(i);
                ans[i] = 1;
            }
        }
        return ans;
    }
}
