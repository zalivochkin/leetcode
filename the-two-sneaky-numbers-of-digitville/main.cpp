
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int> cnt(100, 0);
        for (int num : nums) {
            cnt[num] += 1;
            if (cnt[num] == 2) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};
