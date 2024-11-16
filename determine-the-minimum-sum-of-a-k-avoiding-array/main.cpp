
class Solution {
public:
    int minimumSum(int n, int k) {
        // [1,2,4,5,6] 18
        int min_sum = 0;
        int cur_num = 1;
        // vector<int> arr;
        int arr[n];
        int indx = 0;
        for (int i = 0; i < n; ++i) {
            if (cur_num < k / 2) {
                min_sum += cur_num;
                arr[indx] = cur_num;
                indx++;
            } else if (cur_num > k) {
                min_sum += cur_num;
            } else {
                bool is_good = true;
                for (int j = 0; j < indx; ++j) {
                    if (arr[j] + cur_num == k) {
                        is_good = false;
                        break;
                    }
                }
                if (is_good) {
                    min_sum += cur_num;
                    arr[indx] = cur_num;
                    indx++;
                } else {
                    --i;
                }
            }
            cur_num++;
        }
        return min_sum;
    }
};
