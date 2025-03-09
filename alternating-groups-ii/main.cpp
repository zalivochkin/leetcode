
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const auto n = colors.size();
        int ans = 0;
        int cnt = 0;
        for (auto i = 0; i < n * 2; ++i) {
            if (i > 0 && colors[i % n] == colors[(i - 1) % n]) {
                cnt = 1;
            } else {
                ++cnt;
            }
            if (i >= n && cnt >= k) {
                ++ans;
            }
        }
        return ans;
    }
};
