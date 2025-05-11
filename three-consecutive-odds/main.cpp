
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        const int n = arr.size() - 2;
        for (auto i = 0; i < n; i++) {
            if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1) {
                return true;
            }
        }
        return false;
    }
};
