
class Solution {
public:
    long long dfs(vector<vector<array<long long, 2>>> &f, int limit, int i, int j, int k) {
        const int mod = 1e9 + 7;
        if (i < 0 || j < 0) {
            return 0;
        }
        if (i == 0) {
            return k == 1 && j <= limit;
        }
        if (j == 0) {
            return k == 0 && i <= limit;
        }
        long long &res = f[i][j][k];
        if (res != -1) {
            return res;
        }
        if (k == 0) {
            res = (dfs(f, limit, i - 1, j, 0) + dfs(f, limit, i - 1, j, 1) - dfs(f, limit, i - limit - 1, j, 1) + mod) % mod;
        } else {
            res = (dfs(f, limit, i, j - 1, 0) + dfs(f, limit, i, j - 1, 1) - dfs(f, limit, i, j - limit - 1, 0) + mod) % mod;
        }
        return res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1e9 + 7;
        vector<vector<array<long long, 2>>> f = vector<vector<array<long long, 2>>>(zero + 1, vector<array<long long, 2>>(one + 1, {-1, -1}));
        return (dfs(f, limit, zero, one, 0) + dfs(f, limit, zero, one, 1)) % mod;
    }
};
