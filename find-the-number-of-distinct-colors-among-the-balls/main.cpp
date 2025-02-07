
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> colors;
        unordered_map<int, int> colors_cnts;
        vector<int> res;
        for (auto &query: queries) {
            int ball_num = query[0];
            int ball_color = query[1];
            colors_cnts[ball_color]++;
            if (colors.contains(ball_num)) {
                colors_cnts[colors[ball_num]] -= 1;
                if (colors_cnts[colors[ball_num]] == 0) {
                    colors_cnts.erase(colors[ball_num]);
                }
            }
            colors[ball_num] = ball_color;
            res.push_back(colors_cnts.size());
        }
        return res;
    }
};
