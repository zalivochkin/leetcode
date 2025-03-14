
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int lft = 0;
        int rght = ranges::max(candies);
        while (lft < rght) {
            int mid = midpoint(lft, rght + 1);
            long long cnt = 0;
            for (auto candy : candies) {
                cnt += candy / mid;
            }
            if (cnt >= k) {
                lft = mid;
            } else {
                rght = mid - 1;
            }
        }
        return lft;
    }
};
