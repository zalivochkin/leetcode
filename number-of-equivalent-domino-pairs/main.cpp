
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> cnt(100, 0);
        int ans = 0;
        for (const auto &domino : dominoes) {
            int x = domino[0] < domino[1] ? domino[0] * 10 + domino[1] : domino[1] * 10 + domino[0];
            ans += cnt[x];
            cnt[x] += 1;
        }
        return ans;
    }
};
