
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, bool> visited;
        int ans = 0;
        const auto n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            if (visited[nums[i]]) {
                ans = ceil(static_cast<double>(i + 1) / 3.0);
                break;
            }
            visited[nums[i]] = true;
        }
        return ans;
    }
};
