
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        const auto n = weights.size();
        vector<int> scores(n - 1);
        for (auto i = 0; i < n - 1; ++i) {
            scores[i] = weights[i] + weights[i + 1];
        }
        ranges::sort(scores);
        long long ans = 0;
        for (auto i = 0; i < k - 1; ++i) {
            ans -= scores[i];
            ans += scores[n - 2 - i];
        }
        return ans;
    }
};
