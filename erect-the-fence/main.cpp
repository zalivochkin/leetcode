
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        auto n = trees.size();
        if (n <= 3) {
            return trees;
        }
        vector<vector<int>> res(2 * n);
        sort(trees.begin(), trees.end());
        int k = 0;
        for (size_t i = 0; i < n; ++i) {
            while (k >= 2 && cross(res[k - 2], res[k - 1], trees[i]) < 0) {
                k--;
            }
            res[k++] = trees[i];
        }
        for (size_t i = n - 1, t = k + 1; i > 0; --i) {
            while (k >= t && cross(res[k - 2], res[k - 1], trees[i - 1]) < 0) {
                k--;
            }
            res[k++] = trees[i - 1];
        }
        res.resize(--k);
        if (res[1] == res[k - 1]) {
            res.resize(k / 2 + 1);
        }
        return res;
    }

    long long cross(const vector<int> &a, const vector<int> &b, const vector<int> &o) {
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0]);
    }
};
