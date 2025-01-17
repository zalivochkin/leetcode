
import java.util.*;

class Solution {
    public boolean doesValidArrayExist(int[] derived) {
        int derived_xor = 0;
        for (var num : derived) {
            derived_xor ^= num;
        }
        return derived_xor == 0;
    }
}
