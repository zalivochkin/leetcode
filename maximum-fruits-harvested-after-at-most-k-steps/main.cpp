
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int ans = 0;
        int summ = 0;
        const auto n = fruits.size();
        for (int i = 0, j = 0; j < n; ++j) {
            int pj = fruits[j][0];
            int fj = fruits[j][1];
            summ += fj;
            while (i <= j && pj - fruits[i][0] + min(abs(startPos - fruits[i][0]), abs(startPos - pj)) > k) {
                summ -= fruits[i][1];
                ++i;
            }
            ans = max(ans, summ);
        }
        return ans;
    }
};
