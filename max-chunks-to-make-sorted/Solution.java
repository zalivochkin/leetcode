
import java.util.*;

class Solution {
    public int maxChunksToSorted(int[] arr) {
        int chunks = 1;
        int curMax = arr[0];
        int[] sortedArr = arr.clone();
        Arrays.sort(sortedArr);
        for (var i = 0; i < arr.length - 1; ++i) {
            curMax = Math.max(curMax, arr[i]);
            if (curMax == sortedArr[i]) {
                ++chunks;
                curMax = arr[i + 1];
            }
        }
        return chunks;
    }
}
