class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid, int i, int j, int cur_removed) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] < 0) {
            return INT_MAX;
        }
        int orig = grid[i][j];
        if (cur_removed + orig >= abs_min) {
            dp[i][j] = INT_MAX;
            return INT_MAX;
        }
        if (dp[i][j] != -1 && dp[i][j] < cur_removed + orig) {
             return dp[i][j];
        }
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            abs_min = min(abs_min, cur_removed + orig);
            dp[i][j] = orig;
            return orig;
        }
        grid[i][j] = -1;
        int removed = minimumObstacles(grid, i + 1, j, cur_removed + orig);
        removed = min(removed, minimumObstacles(grid, i, j + 1, cur_removed + orig));
        removed = min(removed, minimumObstacles(grid, i - 1, j, cur_removed + orig));
        removed = min(removed, minimumObstacles(grid, i, j - 1, cur_removed + orig));
        grid[i][j] = orig;
        if (dp[i][j] == -1) {
            dp[i][j] = removed == INT_MAX ? INT_MAX : removed + orig;
        }
        dp[i][j] = min(dp[i][j], removed == INT_MAX ? INT_MAX : removed + orig);
        return dp[i][j];
    }

    int abs_min;
    vector<vector<int>> dp;

    int minimumObstacles(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector dp(n, vector(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        vector<pair<int,int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            const auto [c, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1) {
                return c;
            }
            for (const auto [dx, dy]: dirs) {
                int x =  i + dx;
                int y = j + dy;
                if (x >= 0 && x < n && y >= 0 && y < m && dp[x][y] > grid[x][y] + c) {
                    dp[x][y] = grid[x][y] + c;
                    pq.emplace(grid[x][y] + c, x, y);
                }
            }
        }
        return -1;
    }
};
