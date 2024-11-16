
class Solution {
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
        int n = plantTime.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&growTime](const int lindx, const int rindx) -> bool {
            return growTime[lindx] > growTime[rindx];
        });
        int prev = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            int grow = growTime[indices[i]];
            int plant = plantTime[indices[i]];
            total = max(total, prev + grow + plant);
            prev += plant;
        }
        return total;
    }

};
