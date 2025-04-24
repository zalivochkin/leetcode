
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        const auto cnt = s.size();
        int ans = 0;
        const auto n = nums.size();
        for (auto i = 0; i < n; ++i) {
            s.clear();
            for (auto j = i; j < n; ++j) {
                s.insert(nums[j]);
                if (s.size() == cnt) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
