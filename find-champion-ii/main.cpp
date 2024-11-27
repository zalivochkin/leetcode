class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> teams(n, false);
        for (const auto &edge : edges) {
            teams[edge[1]] = true;
        }
        int chmp = -1;
        for (auto i = 0; i < n; ++i) {
            if (!teams[i]) {
                if (chmp == -1) {
                    chmp = i;
                } else {
                    return -1;
                }
            }
        }
        return chmp;
    }
};
