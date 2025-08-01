
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(List.of(1));
        for (var i = 0; i < numRows - 1; ++i) {
            List<Integer> row = new ArrayList<>();
            row.add(1);
            final var m = ans.get(i).size() - 1;
            for (int j = 0; j < m; ++j) {
                row.add(ans.get(i).get(j) + ans.get(i).get(j + 1));
            }
            row.add(1);
            ans.add(row);
        }
        return ans;
    }
}
