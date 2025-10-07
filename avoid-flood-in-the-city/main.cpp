
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const auto n = rains.size();
        vector<int> ans(n, -1);
        set<int> sunny;
        unordered_map<int, int> rainy;
        for (auto i = 0; i < n; ++i) {
            int rain = rains[i];
            if (rain) {
                if (rainy.count(rain)) {
                    auto it = sunny.upper_bound(rainy[rain]);
                    if (it == sunny.end()) {
                        return {};
                    }
                    ans[*it] = rain;
                    sunny.erase(it);
                }
                rainy[rain] = i;
            } else {
                sunny.insert(i);
                ans[i] = 1;
            }
        }
        return ans;
    }
};
