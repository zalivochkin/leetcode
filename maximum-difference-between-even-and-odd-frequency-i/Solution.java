
class Solution {
    public int maxDifference(String s) {
        int[] freq = new int[26];
        for(char ch : s.toCharArray()){
            freq[ch - 'a']++;
        }
        int maxOdd = 0;
        int minEven = Integer.MAX_VALUE;
        for(int x : freq){
            if(x == 0){
                continue;
            }
            if(x % 2 == 1){
                maxOdd = Math.max(maxOdd, x);
            }else {
                minEven = Math.min(minEven, x);
            }
        }
        return maxOdd - minEven;
    }
}
