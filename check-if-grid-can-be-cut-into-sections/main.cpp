
class Solution {
public:
    bool check(const vector<vector<int>>& rectangles, int is_y) {
        int cnt = 0;
        int curr = rectangles[0][is_y + 2];
        for (const auto &rectangle : rectangles) {
            if (curr <= rectangle[is_y]) {
                ++cnt;
                if (cnt >= 2) {
                    return true;
                }
            }
            curr = max(curr, rectangle[is_y + 2]);
        }
        return false;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        for (auto is_y = 0; is_y < 2; ++is_y) {
            ranges::sort(rectangles, [&](const auto &a, const auto &b) {
                return a[is_y] < b[is_y];
            });
            if (check(rectangles, is_y)) {
                return true;
            }
        }
        return false;
    }
};
