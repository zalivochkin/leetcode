
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        const auto n = nums.size();
        long long cnt = 0;
        map<int, int> mp;
        int l = 0;
        for (int r = 0; r < n; r++) {
            mp[nums[r]] += 1;
            while (l < r && prev(mp.end())->first - mp.begin()->first > 2) {
                mp[nums[l]] -= 1;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                ++l;
            }
            cnt += r - l + 1LL;
        }
        return cnt;
    }
};
