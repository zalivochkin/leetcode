
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> banned_s;
        for (const auto b : banned) {
            if (b <= n) {
                banned_s.insert(b);
            }
        }
        auto cur_sum = 0LL;
        int res = 0;
        for (auto i = 1; i <= n; ++i) {
            if (banned_s.contains(i)) {
                continue;
            }
            cur_sum += i;
            if (cur_sum > maxSum) {
                break;
            }
            ++res;
        }
        return res;
    }
};
