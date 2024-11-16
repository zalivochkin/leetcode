
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int cur_min = 0;
        int cur_max = 0;
        int cur_cnt;
        int seg_max = 0;
        int seg_cnt = 0;
        for (const auto num : nums) {
            cur_cnt = popcount(static_cast<unsigned int>(num));
            if (cur_min < seg_max) {
                return false;
            }
            if (seg_cnt == cur_cnt) {
                cur_min = min(cur_min, num);
                cur_max = max(cur_max, num);
            } else {
                seg_max = cur_max;
                cur_min = cur_max = num;
                seg_cnt = cur_cnt;
            }
        }
        return cur_min >= seg_max;
    }
};
