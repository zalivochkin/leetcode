
class Solution {
public:
    int step_forvard(vector<vector<int>> &grid, size_t n, vector<vector<vector<int>>> &mem, int r1, int c1, int c2) {
        int r2 = r1 + c1 - c2;

        // Out of bounds or thorn cell
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }

        // Memoization check
        if (mem[r1][c1][c2] != -1) {
            return mem[r1][c1][c2];
        }

        // Base case: reached bottom-right corner
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }

        // Calculate cherries collected at (r1, c1) and (r2, c2)
        int cherries = (r1 == r2 && c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];

        // Move right or down
        int max_cherries = step_forvard(grid, n, mem, r1, c1 + 1, c2);
        max_cherries = max(max_cherries, step_forvard(grid, n, mem, r1 + 1, c1, c2));
        // Move down or right
        max_cherries = max(max_cherries, step_forvard(grid, n, mem, r1, c1 + 1, c2 + 1));
        max_cherries = max(max_cherries, step_forvard(grid, n, mem, r1 + 1, c1, c2 + 1));

        // Memoize the result
        mem[r1][c1][c2] = (max_cherries == INT_MIN) ? INT_MIN : max_cherries + cherries;

        return mem[r1][c1][c2];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        auto n = grid.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return max(0, step_forvard(grid, n, memo, 0, 0, 0));
    }
};
