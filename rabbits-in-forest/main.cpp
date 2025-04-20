
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> counter;
        for (auto cnt : answers) {
            counter[cnt] += 1;
        }
        int res = 0;
        for (auto [answer, count] : counter) {
            res += ceil(count / static_cast<double>(answer + 1)) * (answer + 1);
        }
        return res;
    }
};
