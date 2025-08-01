
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.emplace_back(1, 1);
        for (auto i = 0; i < numRows - 1; ++i) {
            vector<int> row;
            row.push_back(1);
            const auto m = ans[i].size() - 1;
            for (auto j = 0; j < m; ++j) {
                row.push_back(ans[i][j] + ans[i][j + 1]);
            }
            row.push_back(1);
            ans.push_back(row);
        }
        return ans;
    }
};
