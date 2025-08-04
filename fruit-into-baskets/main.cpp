
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> cnt;
        int j = 0;
        const auto n = fruits.size();
        for (auto fruit : fruits) {
            cnt[fruit] += 1;
            if (cnt.size() > 2) {
                int y = fruits[j];
                ++j;
                cnt[y] -= 1;
                if (cnt[y] == 0) {
                    cnt.erase(y);
                }
            }
        }
        return n - j;
    }
};
