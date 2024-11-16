
class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        auto n = nums.size();
        vector<vector<int>> segments;
        unordered_map<int, int> start_indexes;
        unordered_map<int, int> end_indexes;
        for (int i = 0; i < n; ++i) {
            if (!start_indexes.contains(nums[i])) {
                start_indexes[nums[i]] = i;
            }
            end_indexes[nums[i]] = i;
        }
        for (auto &start_index : start_indexes) {
            segments.emplace_back(vector<int>{start_index.second, end_indexes[start_index.first]});
        }
        sort(begin(segments), end(segments), [](const vector<int> &lft, const vector<int> &rght) -> bool { return lft[0] < rght[0]; });
        int max_end_index = -1;
        n = 0;
        for (auto &segment : segments) {
            if (segment[0] > max_end_index) {
                n++;
            }
            max_end_index = max(max_end_index, segment[1]);
        }
        long long mod = 1e9 + 7;
        long long res = 1LL;
        for (auto i = 0; i < n - 1; ++i) {
            res *= 2LL;
            res %= mod;
        }
        return res;
    }
};
