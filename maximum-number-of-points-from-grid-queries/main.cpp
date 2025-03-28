
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        const auto l = queries.size();
        vector<pair<int, int>> qs(l);
        for (auto i = 0; i < l; ++i) {
            qs[i] = {queries[i], i};
        }
        ranges::sort(qs);
        vector<int> ans(l);
        const auto n = grid.size();
        const auto m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vis[0][0] = true;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        int cnt = 0;
        const vector<int> dirs = {-1, 0, 1, 0, -1};
        for (auto [v, k] : qs) {
            while (!pq.empty() && get<0>(pq.top()) < v) {
                auto [_, i, j] = pq.top();
                pq.pop();
                ++cnt;
                for (auto h = 0; h < 4; ++h) {
                    int ih = i + dirs[h];
                    int jh = j + dirs[h + 1];
                    if (ih >= 0 && ih < n && jh >= 0 && jh < m && !vis[ih][jh]) {
                        vis[ih][jh] = true;
                        pq.emplace(grid[ih][jh], ih, jh);
                    }
                }
            }
            ans[k] = cnt;
        }
        return ans;
    }
};
