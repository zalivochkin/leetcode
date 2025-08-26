
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int mx = 0;
        for (const auto &dimension : dimensions) {
            int length = dimension[0];
            int width = dimension[1];
            int t = length * length + width * width;
            if (mx < t) {
                mx = t;
                ans = length * width;
            } else if (mx == t) {
                ans = max(ans, length * width);
            }
        }
        return ans;
    }
};
