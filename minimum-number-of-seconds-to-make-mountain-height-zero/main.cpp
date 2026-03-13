
class Solution {
public:
    bool check(int mountainHeight, const vector<int> &workerTimes, long long t) {
        long long h = 0;
        for (int wt : workerTimes) {
            h += (long long) (sqrt(t * 2.0 / wt + 0.25) - 0.5);
        }
        return h >= mountainHeight;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l = 1;
        long long r = numeric_limits<long long>::max();
        while (l < r) {
            long long mid = midpoint(l, r);
            if (check(mountainHeight, workerTimes, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
