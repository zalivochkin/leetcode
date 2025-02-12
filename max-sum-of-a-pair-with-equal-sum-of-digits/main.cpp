
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> groups;
        int max_sum = -1;
        for(auto num : nums) {
            auto tmp_num = num;
            int sum = 0;
            while (tmp_num > 0) {
                sum += tmp_num % 10;
                tmp_num /= 10;
            }
            if(groups.contains(sum)) {
                if(num > groups[sum].first) {
                    groups[sum].second = groups[sum].first;
                    groups[sum].first = num;
                } else if(num > groups[sum].second) {
                    groups[sum].second = num;
                }
                if(groups[sum].second != -1) {
                    max_sum = max(max_sum, groups[sum].first + groups[sum].second);
                }
            } else {
                groups[sum] = make_pair(num, -1);
            }
        }
        return max_sum;
    }
};
