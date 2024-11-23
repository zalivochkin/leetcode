
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        const auto n = box.size();
        const auto m = box[0].size();
        char ch;
        for (auto i = 0; i < n; ++i) {
            for (int j = m - 1; j >= 0; --j) {
                ch = box[i][j];
                if (ch == '.') {
                    for (int k = j - 1; k >= 0 && j >= 0; --k) {
                        if (box[i][k] == '#') {
                            swap(box[i][j], box[i][k]);
                            --j;
                        } else if (box[i][k] == '*') {
                            break;
                        }
                    }
                }
            }
        }
        vector<vector<char>> res(m, vector<char>(n));
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                res[j][n - i - 1] = box[i][j];
            }
        }
        return res;
    }
};
