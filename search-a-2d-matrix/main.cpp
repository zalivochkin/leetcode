
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const auto n = matrix.size();
        const auto m = matrix[0].size();
        int lft = 0;
        int rght = n * m - 1;
        while(rght > lft) {
            int mid = midpoint(lft, rght);
            int i = mid / m;
            int j = mid % m;
            if(matrix[i][j] == target) {
                return true;
            } else if(matrix[i][j] < target ) {
                lft = mid + 1;
            } else {
                rght = mid - 1;
            }
        }
        return false;
    }
};
