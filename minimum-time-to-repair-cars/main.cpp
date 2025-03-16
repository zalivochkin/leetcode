
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long lft = 0;
        long long rght = 1LL * ranks[0] * cars * cars;
        while (lft < rght) {
            long long mid = midpoint(lft, rght);
            long long cnt = 0;
            for (auto rank : ranks) {
                cnt += static_cast<long long>(sqrt(mid / rank));
            }
            if (cnt >= cars) {
                rght = mid;
            } else {
                lft = mid + 1;
            }
        }
        return lft;
    }
};
