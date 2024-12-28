
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const auto n = nums.size();
        vector<int> res(3);
        vector<int> sums(4, 0);
        vector<int> maxs(2, 0);
        vector<int> idxex(3, 0);
        for (auto i = k * 2; i < n; ++i) {
            sums[1] += nums[i - k * 2];
            sums[2] += nums[i - k];
            sums[3] += nums[i];
            if (i >= k * 3 - 1) {
                if (sums[1] > maxs[0]) {
                    maxs[0] = sums[1];
                    idxex[0] = i - k * 3 + 1;
                }
                if (maxs[0] + sums[2] > maxs[1]) {
                    maxs[1] = maxs[0] + sums[2];
                    idxex[1] = idxex[0];
                    idxex[2] = i - k * 2 + 1;
                }
                if (maxs[1] + sums[3] > sums[0]) {
                    sums[0] = maxs[1] + sums[3];
                    res[0] = idxex[1];
                    res[1] = idxex[2];
                    res[2] = i - k + 1;
                }
                sums[1] -= nums[i - k * 3 + 1];
                sums[2] -= nums[i - k * 2 + 1];
                sums[3] -= nums[i - k + 1];
            }
        }
        return res;
    }
};
