
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        auto n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) -> bool { return a[0] < b[0]; });
        vector<int> intervals_ends(n);
        for (auto i = 0; i < n; ++i) {
            intervals_ends[i] = intervals[i][1];
        }
        sort(intervals_ends.begin(), intervals_ends.end());
        int groups = 0;
        int cur_end = 0;
        for (const auto &interval : intervals) {
            if (interval[0] <= intervals_ends[cur_end]) {
                ++groups;
            } else {
                cur_end++;
            }
        }
        return groups;
    }
};
