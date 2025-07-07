
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        unordered_map<int, vector<int>> d;
        int i = numeric_limits<int>::max();
        int j = 0;
        for (const auto &event : events) {
            int s = event[0];
            int e = event[1];
            d[s].push_back(e);
            i = min(i, s);
            j = max(j, e);
        }
        priority_queue<int, vector<int>, greater<>> q;
        int ans = 0;
        for (auto s = i; s <= j; ++s) {
            while (!q.empty() && q.top() < s) {
                q.pop();
            }
            for (int e : d[s]) {
                q.push(e);
            }
            if (!q.empty()) {
                ++ans;
                q.pop();
            }
        }
        return ans;
    }
};
