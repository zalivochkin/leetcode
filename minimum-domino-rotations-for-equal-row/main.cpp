
class Solution {
public:
    int fn(vector<int>& tops, vector<int>& bottoms, int x) {
        int cnt1 = 0;
        int cnt2 = 0;
        const auto n = tops.size();
        for (int i = 0; i < n; ++i) {
            if (tops[i] != x && bottoms[i] != x) {
                return n + 1;
            }
            if (tops[i] == x) {
                ++cnt1;
            }
            if (bottoms[i] == x) {
                ++cnt2;
            }
        }
        return n - max(cnt1, cnt2);
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const auto n = tops.size();
        int ans = min(fn(tops, bottoms, tops[0]), fn(tops, bottoms, bottoms[0]));
        return ans > n ? -1 : ans;
    }
};
