
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        const auto n = grid.size();
        map<vector<int>, int> mp;
        for (const auto &vec : grid) {
            mp[vec] += 1;
        }
        int res = 0;
        vector<int> vec(n);
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < n; ++j) {
                vec[j] = grid[j][i];
            }
            res += mp[vec];
        }
        return res;
    }
};
