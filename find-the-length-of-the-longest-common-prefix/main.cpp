
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        auto n = arr1.size();
        auto m = arr2.size();
        if (n > m) {
            swap(arr1, arr2);
            swap(n, m);
        }
        for (auto i = 0; i < n; ++i) {
            while (arr1[i] > 0) {
                st.insert(arr1[i]);
                arr1[i] /= 10;
            }
        }
        int max_len = 0;
        for (auto i = 0; i < m; ++i) {
            while (arr2[i] > 0) {
                if (st.contains(arr2[i])) {
                    max_len = max(max_len, static_cast<int>(log10(arr2[i]) + 1));
                }
                arr2[i] /= 10;
            }
        }
        return max_len;
    }
};
