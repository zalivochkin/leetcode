
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int mod = 1e9 + 7;
        vector<int> powers;
        while (n) {
            int x = n & -n;
            powers.emplace_back(x);
            n -= x;
        }
        vector<int> ans;
        for (const auto &query : queries) {
            int l = query[0];
            int r = query[1];
            long long x = 1l;
            for (auto j = l; j <= r; ++j) {
                x = (x * powers[j]) % mod;
            }
            ans.emplace_back(x);
        }
        return ans;
    }
};
