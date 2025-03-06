
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const auto n = grid.size();
        vector<int> cnt(n * n + 1);
        vector<int> ans(2);
        for (const auto &row : grid) {
            for (auto x : row) {
                cnt[x] += 1;
                if (cnt[x] == 2) {
                    ans[0] = x;
                }
            }
        }
        int x = 1;
        while (true) {
            if (cnt[x] == 0) {
                ans[1] = x;
                return ans;
            }
            ++x;
        }
    }
};
