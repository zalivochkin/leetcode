
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const auto n = mat.size();
        const auto m = mat[0].size();
        unordered_map<int, pair<int, int>> idxs;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                idxs[mat[i][j]] = {i, j};
            }
        }
        vector<int> row(n);
        vector<int> col(m);
        int k = 0;
        while (true) {
            const auto &idx = idxs[arr[k]];
            row[idx.first] += 1;
            col[idx.second] += 1;
            if (row[idx.first] == m || col[idx.second] == n) {
                return k;
            }
            ++k;
        }
    }
};
