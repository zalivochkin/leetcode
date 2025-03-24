
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        const auto n = meetings.size();
        ranges::sort(meetings, [](const auto &a, const auto &b) {return a[0] < b[0];});
        int res = meetings[0][0] - 1;
        for (auto i = 1; i < n; ++i) {
            if (meetings[i][0] <= meetings[i - 1][1]) {
                meetings[i][1] = max(meetings[i][1], meetings[i - 1][1]);
            } else {
                res += meetings[i][0] - meetings[i - 1][1] - 1;
            }
        }
        res += days - meetings[n - 1][1];
        return res;
    }
};
