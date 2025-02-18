class Solution {
public:
    void dfs(bitset<20> &udg, bitset<20> &dg, bitset<10> &cols, int &ans, int n, int i) {
        if (i == n) {
            ++ans;
            return;
        }
        for (auto j = 0; j < n; ++j) {
            int a = i + j;
            int b = i - j + n;
            if (cols[j] || dg[a] || udg[b]) {
                continue;
            }
            cols[j] = dg[a] = udg[b] = 1;
            dfs(udg, dg, cols, ans, n, i + 1);
            cols[j] = dg[a] = udg[b] = 0;
        }
    }

    int totalNQueens(int n) {
        bitset<10> cols;
        bitset<20> dg;
        bitset<20> udg;
        int ans = 0;
        dfs(udg, dg, cols, ans, n, 0);
        return ans;
    }
};
