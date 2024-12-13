
class Solution {
public:
    class Comp {
    public:
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
            if (p1.second != p2.second) {
                return p1.second > p2.second;
            }
            return p1.first > p2.first;
        }
    };
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
        const auto n = nums.size();
        bool *marked = new bool[n + 2];
        for (auto i = 0; i < n; ++i) {
            pq.emplace(i, nums[i]);
            marked[i] = false;
        }
        marked[n] = false;
        long long score = 0LL;
        while (!pq.empty()) {
            auto [index, cur_score] = pq.top();
            pq.pop();
            if (!marked[index + 1]) {
                score += cur_score;
                marked[index] = true;
                marked[index + 1] = true;
                marked[index + 2] = true;
            }
        }
        delete[] marked;
        return score;
    }
};
