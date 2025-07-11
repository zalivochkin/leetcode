
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> idle;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        for (auto i = 0; i < n; ++i) {
            idle.push(i);
        }
        vector<int> cnt(n);
        ranges::sort(meetings);
        for (const auto &meeting : meetings) {
            auto s = meeting[0];
            auto e = meeting[1];
            while (!busy.empty() && busy.top().first <= s) {
                idle.push(busy.top().second);
                busy.pop();
            }
            int i = 0;
            if (!idle.empty()) {
                i = idle.top();
                idle.pop();
                busy.emplace(e, i);
            } else {
                auto [k, l] = busy.top();
                busy.pop();
                i = l;
                busy.emplace(k + e - s, i);
            }
            ++cnt[i];
        }
        int ans = 0;
        for (auto i = 0; i < n; ++i) {
            if (cnt[ans] < cnt[i]) {
                ans = i;
            }
        }
        return ans;
    }
};
