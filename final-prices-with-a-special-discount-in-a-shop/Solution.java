
import java.util.*;

class Solution {
    public int[] finalPrices(int[] prices) {
        Deque<Integer> st = new ArrayDeque<>();
        for (var i = 0; i < prices.length; ++i) {
            while (!st.isEmpty() && prices[i] <= prices[st.peek()]) {
                prices[st.peek()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
}
