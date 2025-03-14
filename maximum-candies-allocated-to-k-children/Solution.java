
class Solution {
    public int maximumCandies(int[] candies, long k) {
        int lft = 0;
        int rght = Arrays.stream(candies).max().getAsInt();
        while (lft < rght) {
            int mid = lft + (rght + 1 - lft) / 2;
            long cnt = 0;
            for (var candy : candies) {
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
}
