
class Solution {
public:
    int maxSum(vector<int>& nums) {
        ranges::sort(nums);
        if (nums[nums.size() - 1] < 0) {
            return nums[nums.size() - 1];
        }
        unordered_map<int, bool> visited;
        int summ = 0;
        for (auto num : nums) {
            if (num > 0 && !visited.contains(num)) {
                summ += num;
                visited[num] = true;
            }
        }
        return summ;
    }
};
