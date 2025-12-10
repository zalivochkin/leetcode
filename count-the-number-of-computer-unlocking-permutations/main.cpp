
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const int mod = 1e9 + 7;
        long long ans = 1;
        const auto n = complexity.size();
        for (auto i = 1; i < n; ++i) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
            ans = ans * i % mod;
        }
        return ans;
    }
};
