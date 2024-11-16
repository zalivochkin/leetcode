
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        auto n = nums.size();
        stack<int> stack;
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && nums[i] < stack.top() && n - i - 1 >= k - stack.size()) {
                stack.pop();
            }
            if (stack.size() < k) {
                stack.push(nums[i]);
            }
        }
        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    void mostCompetitive(vector<int> &res, vector<int>& nums, int start_index, int k) {
        auto n = nums.size();
        if (k == 0 || n - start_index == 0) {
            return;
        }
        auto max_el = nums[start_index];
        auto max_el_pos = start_index;
        for (auto i = start_index; i <= n - k; ++i) {
            if (nums[i] < max_el) {
                max_el = nums[i];
                max_el_pos = i;
            }
        }
        res.push_back(max_el);
        mostCompetitive(res, nums, max_el_pos + 1, k - 1);
    }
};
