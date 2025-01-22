
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const auto n = isWater.size();
        const auto m = isWater[0].size();
        const vector<int> dirs{-1, 0, 1, 0, -1};
        vector<vector<int>> res(n, vector<int>(m));
        queue<pair<int, int>> q;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                res[i][j] = isWater[i][j] - 1;
                if (res[i][j] == 0) {
                    q.emplace(i, j);
                }
            }
        }
        int i, j;
        while (!q.empty()) {
            for (auto t = q.size(); t; --t) {
                auto [frst, scnd] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    i = frst + dirs[k];
                    j = scnd + dirs[k + 1];
                    if (i >= 0 && i < n && j >= 0 && j < m && res[i][j] == -1) {
                        res[i][j] = res[frst][scnd] + 1;
                        q.emplace(i, j);
                    }
                }
            }
        }
        return res;
    }
};
