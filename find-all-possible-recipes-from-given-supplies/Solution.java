
import java.util.*;

class Solution {
    public List<String> findAllRecipes(String[] recipes, List<List<String>> ingredients, String[] supplies) {
        final var n = recipes.length;
        Map<String, List<String>> graph = new HashMap<>();
        Map<String, Integer> indeg = new HashMap<>();
        for (var i = 0; i < n; ++i) {
            for (String v : ingredients.get(i)) {
                graph.computeIfAbsent(v, k -> new ArrayList<>()).add(recipes[i]);
            }
            indeg.put(recipes[i], ingredients.get(i).size());
        }
        Deque<String> q = new ArrayDeque<>();
        for (String supply : supplies) {
            q.offer(supply);
        }
        List<String> ans = new ArrayList<>();
        while (!q.isEmpty()) {
            for (int i = q.size(); i > 0; --i) {
                String supply1 = q.pollFirst();
                for (String supply2 : graph.getOrDefault(supply1, Collections.emptyList())) {
                    indeg.put(supply2, indeg.get(supply2) - 1);
                    if (indeg.get(supply2) == 0) {
                        ans.add(supply2);
                        q.offer(supply2);
                    }
                }
            }
        }
        return ans;
    }
}
