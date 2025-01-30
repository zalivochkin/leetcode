
import java.util.*;

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        final var n = matrix.length;
        final var m = matrix[0].length;
        int lft = 0;
        int rght = n * m - 1;
        while (rght >= lft)  {
            int mid = lft + (rght - lft) / 2;
            int i = mid / m;
            int j = mid % m;
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target ) {
                lft = mid + 1;
            } else {
                rght = mid - 1;
            }
        }
        return false;
    }
}
