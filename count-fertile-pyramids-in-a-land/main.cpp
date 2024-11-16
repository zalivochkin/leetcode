
class Solution {
public:
    int count(vector<vector<int>> grid) {
        int i;
        int j;
        const int n = grid.size();
        const int m = grid[0].size();
        int res = 0;
        for (i = 1; i < n; i++) {
            for (j = 1; j < m - 1; j++) {
                if (grid[i][j] && grid[i - 1][j]) {
                    grid[i][j] = min(grid[i - 1][j - 1], grid[i - 1][j + 1]) + 1;
                    res += grid[i][j] - 1;
                }
            }
        }
        return res;
    }

    int countPyramids(vector<vector<int> > &grid) {
        int ans = count(grid);
        reverse(grid.begin(), grid.end());
        ans += count(grid);
        return ans;
    }
};
