
class Solution {
public:
    int minNumberOperationsV2(vector<int>& target) {
        int ans = target[0];
        for (int i = 1; i < target.size(); ++i) {
            if (target[i] - target[i - 1] > 0) {
                ans += target[i] - target[i - 1];
            }
        }
        return ans;
    }
};
