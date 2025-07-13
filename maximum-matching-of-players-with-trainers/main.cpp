
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        ranges::sort(players);
        ranges::sort(trainers);
        const auto m = players.size();
        const auto n = trainers.size();
        for (auto i = 0, j = 0; i < m; ++i) {
            while (j < n && trainers[j] < players[i]) {
                ++j;
            }
            if (j++ >= n) {
                return i;
            }
        }
        return m;
    }
};
