
class Solution {
public:
    int helper(std::vector<std::vector<int>> &richer, std::vector<int> &quiet, int person, std::vector<int> &res) {
        if (res[person] != -1) {
            return res[person];
        }

        int least_quiet = person;
        for (const auto &richer_: richer) {
            if (richer_[1] == person) {
                int new_least_quiet = helper(richer, quiet, richer_[0], res);
                if (quiet[new_least_quiet] < quiet[least_quiet]) {
                    least_quiet = new_least_quiet;
                }
            }
        }
        res[person] = least_quiet;
        return least_quiet;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        std::vector<int> res(quiet.size(), -1);
        for (int i = 0; i < quiet.size(); ++i) {
            res[i] = helper(richer, quiet, i, res);
        }
        return res;
    }
};
