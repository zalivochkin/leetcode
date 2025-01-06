
class Solution {
public:
    vector<int> minOperations(string boxes) {
        const auto n = boxes.size();
        vector<int> res(n);
        int cnt = 0;
        for (auto i = 1; i < n; ++i) {
            cnt += boxes[i - 1] == '1' ? 1 : 0;
            res[i] = res[i - 1] + cnt;
        }
        cnt = 0;
        int summ = 0;
        for (int i = n - 2; i >= 0; --i) {
            cnt += boxes[i + 1] == '1' ? 1 : 0;
            summ += cnt;
            res[i] += summ;
        }
        return res;
    }
};
