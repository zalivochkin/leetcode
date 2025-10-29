
class Solution {
    public int smallestNumber(int n) {
        return (1 << (Integer.SIZE - Integer.numberOfLeadingZeros(n))) - 1;
    }
}
