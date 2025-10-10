
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = numeric_limits<int>::min();
        const auto n = energy.size();
        for (auto i = n - k; i < n; ++i) {
            for (int j = i, s = 0; j >= 0; j -= k) {
                s += energy[j];
                ans = max(ans, s);
            }
        }
        return ans;
    }
};
