class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> count;
        string key;
        for (const auto &row: matrix) {
            key.clear();
            for (const auto num : row) {
                if (row[0] == 1) {
                    key.push_back('0' + (1 - num));
                } else {
                    key.push_back('0' + num);
                }
            }
            count[key]++;
        }
        int res = 0;
        for (const auto &[_, cnt]: count) {
            res = max(res, cnt);
        }
        return res;
    }
};
