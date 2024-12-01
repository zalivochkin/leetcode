
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        const auto n = arr.size();
        for(auto i = 0; i < n; ++i) {
            for(auto j = 0; j < n; ++j) {
                if (i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
