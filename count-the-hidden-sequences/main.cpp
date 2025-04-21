
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long x = 0;
        long long mi = 0;
        long long mx = 0;
        for (auto d : differences) {
            x += d;
            mi = min(mi, x);
            mx = max(mx, x);
        }
        return max(upper - lower - (mx - mi) + 1, 0LL);
    }
};
