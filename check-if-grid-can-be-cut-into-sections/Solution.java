
import java.util.*;

class Solution {
    boolean check(int[][] rectangles, int is_y) {
        int cnt = 0;
        int curr = rectangles[0][is_y + 2];
        for (var rectangle : rectangles) {
            if (curr <= rectangle[is_y]) {
                ++cnt;
                if (cnt >= 2) {
                    return true;
                }
            }
            curr = Math.max(curr, rectangle[is_y + 2]);
        }
        return false;
    }

    public boolean checkValidCuts(int n, int[][] rectangles) {
        for (var is_y = 0; is_y < 2; ++is_y) {
            final var indx = is_y;
            Arrays.sort(rectangles, (a, b) -> Integer.compare(a[indx], b[indx]));
            if (check(rectangles, is_y)) {
                return true;
            }
        }
        return false;
    }
}
