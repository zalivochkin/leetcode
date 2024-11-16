
struct pt {
    int pos;
    bool is_first;
    int index;
};

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        const auto n = firstList.size();
        const auto m = secondList.size();
        size_t i = 0;
        size_t j = 0;
        int start_pos, end_pos;
        vector<vector<int>> res;
        while (i < n && j < m) {
            start_pos = max(firstList[i][0], secondList[j][0]);
            end_pos = min(firstList[i][1], secondList[j][1]);
            if (start_pos <= end_pos) {
                res.push_back({start_pos, end_pos});
            }
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
