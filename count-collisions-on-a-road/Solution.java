
class Solution {
    public int countCollisions(String directions) {
        char[] ds = directions.toCharArray();
        int l = 0;
        int r = ds.length - 1;
        int count = 0;
        while (l <= r && ds[l] == 'L') {
            l++;
        }
        while (l <= r && ds[r] == 'R') {
            r--;
        }
        for (int i = l; i <= r; i++) {
            if (ds[i] != 'S') {
                ++count;
            }
        }
        return count;
    }
}
