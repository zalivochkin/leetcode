
import java.util.*;

class Solution {
    public int reverseBits(int n) {
        int res = 0;
        for (var i = 0; i < 32; ++i) {
            res = res << 1;
            res |= (n & 1);
            n = n >> 1;
        }
        return res;
    }
}
