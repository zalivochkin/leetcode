
class Solution {
public:
    int bestClosingTime(string customers) {
        const auto n = customers.size();
        vector<int> s(n + 1);
        for (auto i = 0; i < n; ++i) {
            if (customers[i] == 'Y') {
                s[i + 1] = s[i] + 1;
            } else {
                s[i + 1] = s[i];
            }
        }
        int ans = 0;
        int cost = numeric_limits<int>::max();
        for (auto j = 0; j <= n; ++j) {
            int t = j - s[j] + s[n] - s[j];
            if (cost > t) {
                ans = j;
                cost = t;
            }
        }
        return ans;
    }
};
