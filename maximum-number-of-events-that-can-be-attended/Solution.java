
class Solution {
    public int maxEvents(int[][] events) {
        Map<Integer, List<Integer>> d = new HashMap<>();
        int i = Integer.MAX_VALUE;
        int j = 0;
        for (var event : events) {
            int s = event[0];
            int e = event[1];
            d.computeIfAbsent(s, k -> new ArrayList<>()).add(e);
            i = Math.min(i, s);
            j = Math.max(j, e);
        }
        PriorityQueue<Integer> q = new PriorityQueue<>();
        int ans = 0;
        for (var s = i; s <= j; ++s) {
            while (!q.isEmpty() && q.peek() < s) {
                q.poll();
            }
            for (int e : d.getOrDefault(s, Collections.emptyList())) {
                q.offer(e);
            }
            if (!q.isEmpty()) {
                q.poll();
                ++ans;
            }
        }
        return ans;
    }
}
