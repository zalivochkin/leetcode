
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int pre = 0;
        for (const auto &row : bank) {
            int cur = count(row.begin(), row.end(), '1');
            if (cur) {
                ans += pre * cur;
                pre = cur;
            }
        }
        return ans;
    }
};
