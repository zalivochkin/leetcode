
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int cnt = 0;
        vector<bool> st(right + 1, false);
        vector<int> prime(right + 1);
        for (auto i = 2; i <= right; ++i) {
            if (!st[i]) {
                prime[cnt] = i;
                ++cnt;
            }
            for (auto j = 0; prime[j] <= right / i; ++j) {
                st[prime[j] * i] = true;
                if (i % prime[j] == 0) {
                    break;
                }
            }
        }
        int i = -1;
        int j = -1;
        for (auto k = 0; k < cnt; ++k) {
            if (prime[k] >= left && prime[k] <= right) {
                if (i == -1) {
                    i = k;
                }
                j = k;
            }
        }
        vector<int> ans(2, -1);
        if (i == j || i == -1) {
            return ans;
        }
        int mi = 1 << 30;
        for (auto k = i; k < j; ++k) {
            int d = prime[k + 1] - prime[k];
            if (d < mi) {
                mi = d;
                ans[0] = prime[k];
                ans[1] = prime[k + 1];
            }
        }
        return ans;
    }
};
