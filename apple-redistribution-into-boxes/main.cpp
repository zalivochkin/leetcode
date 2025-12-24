
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
        int s = accumulate(apple.begin(), apple.end(), 0);
        int i = 1;
        while (true) {
            s -= capacity[i - 1];
            if (s <= 0) {
                return i;
            }
            ++i;
        }
    }
};
