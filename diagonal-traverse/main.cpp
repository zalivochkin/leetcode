
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const auto n = mat.size();
        const auto m = mat[0].size();
        vector<int> ans;
        vector<int> tmp;
        for (auto k = 0; k < n + m - 1; ++k) {
            int i = k < m ? 0 : k - m + 1;
            int j = k < m ? k : m - 1;
            while (i < n && j >= 0) {
                tmp.push_back(mat[i][j]);
                ++i;
                --j;
            }
            if (k % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }
            for (auto num : tmp) {
                ans.push_back(num);
            }
            tmp.clear();
        }
        return ans;
    }
};
