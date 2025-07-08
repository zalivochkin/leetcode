
class Solution {
public:
    int search(vector<vector<int>>& events, int i, int j, int k) {
        while (i != j) {
            if (events[(i + j) / 2][0] > k) {
                j = (i + j) / 2;
            } else {
                i = (i + j) / 2 + 1;
            }
        }
        return i;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        ranges::sort(events);
        const auto n = events.size();
        vector<int> track(n, 0);
        for (auto i = 0; i < n; i++) {
            if (events[n - 1][0] > events[i][1]) {
                track[i] = search(events, i + 1, n - 1, events[i][1]);
            } else {
                track[i] = i;
            }
        }
        vector<vector<int>> v;
        for (auto i = 0; i <= k; i++) {
            vector<int> temp(events.size(), 0);
            v.push_back(temp);
        }
        vector<int> temp(n, 0);
        for (auto i = 1; i <= k; i++) {
            int maxi = 0;
            for (int j = n - 1; j >= 0; j--) {
                maxi = max(maxi, v[i - 1][j]);
                temp[j] = maxi;
            }
            for (auto j = 0; j < n; j++) {
                if (track[j] == j) {
                    v[i][j] = max(v[i - 1][j], events[j][2]);
                    continue;
                }
                v[i][j] = events[j][2] + temp[track[j]];
            }
        }
        int ans = 0;
        for (auto i = 0; i < n; i++) {
            ans = max(ans, v[k][i]);
        }
        return ans;
    }
};
