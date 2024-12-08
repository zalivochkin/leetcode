
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        const auto n = events.size();
        vector<int> maxs(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            maxs[i] = max(maxs[i + 1], events[i][2]);
        }
        int res = 0;
        int lft, rght, mid;
        for (auto& event : events) {
            lft = 0;
            rght = n;
            while (lft < rght) {
                mid = lft + (rght - lft) / 2;
                if (events[mid][0] > event[1]) {
                    rght = mid;
                } else {
                    lft = mid + 1;
                }
            }
            if (lft < n) {
                event[2] += maxs[lft];
            }
            res = max(res, event[2]);
        }
        return res;
    }
};
