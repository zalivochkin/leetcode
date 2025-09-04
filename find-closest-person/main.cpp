
class Solution {
public:
    int findClosest(int x, int y, int z) {
        auto distx = abs(z - x);
        auto disty = abs(z - y);
        if (distx == disty) {
            return 0;
        } else if (distx < disty) {
            return 1;
        }
        return 2;
    }
};
