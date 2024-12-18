
import java.util.*;

class Solution {
    public int maxProfit(int[] prices) {
        int maxP = 0;
        int leftIndx = 0;
        for (int rightIndx = 1; rightIndx < prices.length; ++rightIndx) {
            if (prices[rightIndx] < prices[leftIndx]) {
                leftIndx = rightIndx;
            } else {
                maxP = Math.max(maxP, prices[rightIndx] - prices[leftIndx]);
            }
        }
        return maxP;
    }
}
