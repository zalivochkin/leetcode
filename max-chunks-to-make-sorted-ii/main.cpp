
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto n = arr.size();
        if (n == 0) {
            return 0;
        }
        vector<int> arr_mins(n);
        arr_mins[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            arr_mins[i] = min(arr_mins[i + 1], arr[i]);
        }
        int max_chunks = 1;
        int arr_max = INT_MIN;
        for (auto i = 0; i < n; ++i) {
            arr_max = max(arr_max, arr[i]);
            if (arr_max <= arr_mins[i + 1] && i + 1 < n) {
                max_chunks++;
            }
        }
        return max_chunks;
    }
};
