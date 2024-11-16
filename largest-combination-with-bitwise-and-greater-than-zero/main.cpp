
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_set = 0;
        int b_bit_set;
        for (char b = 0; b < 24; ++b) {
            b_bit_set = 0;
            for (const auto candidat: candidates) {
                b_bit_set += (candidat >> b) & 1;
            }
            max_set = max(max_set, b_bit_set);
        }
        return max_set;
    }
};
