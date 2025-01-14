
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const auto n = A.size();
        vector<int> vis(n + 1, 1);
        int summ = 0;
        vector<int> res(n);
        for (auto i = 0; i < n; ++i) {
            vis[A[i]] ^= 1;
            summ += vis[A[i]];
            vis[B[i]] ^= 1;
            summ += vis[B[i]];
            res[i] = summ;
        }
        return res;
    }
};
