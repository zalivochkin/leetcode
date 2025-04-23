
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> cnts;
        int ans = 0;
        int mx = 0;
        int s = 0;
        for (auto i = 1; i <= n; ++i) {
            s = 0;
            for (auto x = i; x; x /= 10) {
                s += x % 10;
            }
            cnts[s] += 1;
            if (mx < cnts[s]) {
                mx = cnts[s];
                ans = 1;
            } else if (mx == cnts[s]) {
                ++ans;
            }
        }
        return ans;
    }
};
