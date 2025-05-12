
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        for (auto digit : digits) {
            cnt[digit] += 1;
        }
        vector<int> ans;
        vector<int> cnt1(10);
        for (auto number = 100; number < 1000; number += 2) {
            ranges::fill(cnt1, 0);
            for (int tmp_number = number; tmp_number != 0; tmp_number /= 10) {
                cnt1[tmp_number % 10] += 1;
            }
            bool ok = true;
            for (int i = 0; i < 10 && ok; ++i) {
                ok = cnt[i] >= cnt1[i];
            }
            if (ok) {
                ans.push_back(number);
            }
        }
        return ans;
    }
};
