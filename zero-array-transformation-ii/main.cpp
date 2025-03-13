
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const auto n = nums.size();
        const auto m = queries.size();
        vector<int> diff(n + 1, 0);
        int sum = 0;
        int pos = 0;
        for (auto i = 0; i < n; ++i) {
            while (sum + diff[i] < nums[i]) {
                if (pos == m) {
                    return -1;
                }
                int start = queries[pos][0];
                int end = queries[pos][1];
                int val = queries[pos][2];
                ++pos;
                if (end < i) {
                    continue;
                }
                diff[max(start, i)] += val;
                diff[end + 1] -= val;
            }
            sum += diff[i];
        }
        return pos;
    }
};
