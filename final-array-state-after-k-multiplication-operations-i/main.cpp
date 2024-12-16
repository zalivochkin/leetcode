
class Solution {
public:
    class Comp {
    public:
        bool operator()(vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? b[1] < a[1] : b[0] < a[0];
        }
    };
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        const auto n = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
        for (auto i = 0; i < n; ++i) {
            pq.push(vector<int>{nums[i], i});
        }
        for (auto i = 0; i < k; ++i) {
            auto el = pq.top();
            el[0] *= multiplier;
            nums[el[1]] = el[0];
            pq.push(el);
        }
        return nums;
    }
};
