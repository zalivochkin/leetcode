
class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> ans = new ArrayList<>();
        ans.add(folder[0]);
        final var k = folder.length;
        for (var i = 1; i < k; ++i) {
            int m = ans.get(ans.size() - 1).length();
            final var n = folder[i].length();
            if (m >= n || !(ans.get(ans.size() - 1).equals(folder[i].substring(0, m)) && folder[i].charAt(m) == '/')) {
                ans.add(folder[i]);
            }
        }
        return ans;
    }
}
