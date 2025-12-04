
class Solution {
public:
    int countCollisions(string directions) {
        int l = 0;
        int r = directions.size() - 1;
        int count = 0;
        while (l <= r && directions[l] == 'L') {
            l++;
        }
        while (l <= r && directions[r] == 'R') {
            r--;
        }
        for (int i = l; i <= r; i++) {
            if (directions[i] != 'S') {
                ++count;
            }
        }
        return count;
    }
};
