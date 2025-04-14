
class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int count = 0;
        final var n = arr.length;
        for (var i = 0; i < n; i++) {
            for (var j = i + 1; j < n; j++) {
                for (var k = j + 1; k < n; k++) {
                    if (Math.abs(arr[i] - arr[j]) <= a && Math.abs(arr[j] - arr[k]) <= b && Math.abs(arr[i] - arr[k]) <= c) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}
