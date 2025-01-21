
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const auto n = grid[0].size();
        long long s1 = 0;
        for (const auto &pts : grid[0]) {
            s1 += pts;
        }
        long long s2 = 0;
        long long res = LONG_MAX;
        for (auto i = 0; i < n; ++i) {
            s1 -= grid[0][i];
            res = min(res, max(s1, s2));
            s2 += grid[1][i];
        }
        return res;
    }
};
