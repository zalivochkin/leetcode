
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const auto n = nums.size();
        vector<int> diff(n + 1);
        for (const auto &query : queries) {
            diff[query[0]] += 1;
            diff[query[1] + 1] -= 1;
        }
        int current = 0;
        for (auto i = 0; i < n; i++) {
            current += diff[i];
            if (nums[i] > current) {
                return false;
            }
        }
        return true;
    }
};
