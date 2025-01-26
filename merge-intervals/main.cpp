
class Solution {
public:
    class Comp {
    public:
        bool operator () (const vector<int> &v1, const vector<int> &v2) const {
            return v1[0] < v2[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        Comp comp;
        sort(intervals.begin(), intervals.end(), comp);
        for (auto i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= intervals[i - 1][1]) {
                intervals[i - 1][1] = max(intervals[i - 1][1], intervals[i][1]);
                intervals.erase(intervals.begin() + i);
                --i;
            }
        }
        return intervals;
    }
};
