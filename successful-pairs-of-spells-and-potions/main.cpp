
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ranges::sort(potions);
        vector<int> ans;
        const auto n = potions.size();
        for (int &spell : spells) {
            int i = lower_bound(potions.begin(), potions.end(), success * 1.0 / spell) - potions.begin();
            ans.push_back(n - i);
        }
        return ans;
    }
};
