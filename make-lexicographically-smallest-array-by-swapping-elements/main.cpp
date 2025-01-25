
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const auto n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        vector<int> res(n);
        int i = 0, j;
        while (i < n) {
            j = i + 1;
            while (j < n && nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                ++j;
            }
            vector<int> tmp(idx.begin() + i, idx.begin() + j);
            sort(tmp.begin(), tmp.end());
            for (auto k = i; k < j; ++k) {
                res[tmp[k - i]] = nums[idx[k]];
            }
            i = j;
        }
        return res;
    }
};
