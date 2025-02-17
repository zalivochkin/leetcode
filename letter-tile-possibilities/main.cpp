
class Solution {
public:
    int dfs(unordered_map<char, int> &cnts) {
        int res = 0;
        for (auto [ch, cnt] : cnts) {
            if (cnt > 0) {
                ++res;
                cnts[ch] -= 1;
                res += dfs(cnts);
                cnts[ch] += 1;
            }
        }
        return res;
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> cnts;
        for (const auto ch : tiles) {
            cnts[ch] += 1;
        }
        return dfs(cnts);
    }
};
