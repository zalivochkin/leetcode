
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        const auto n = values.size();
        int Max = 0;
        int res = 0;
        for (auto i = 0; i < n; ++i) {
            res = max(res, values[i] - i + Max);
            Max = max(Max, values[i] + i);
        }
        return res;
    }
};
