
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        auto n = skill.size();
        sort(skill.begin(), skill.end());
        long long res = 0;
        long long skill_sum = skill[0] + skill[n - 1];
        for (auto i = 0; i < n / 2; ++i) {
            if (skill[i] + skill[n - i - 1] != skill_sum) {
                return -1;
            }
            res += skill[i] * skill[n - i - 1];
        }
        return res;
    }
};
