
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const auto n = code.size();
        vector<int> res(n);
        if (k == 0) {
            fill(res.begin(), res.end(), 0);
        } else if (k > 0) {
            int sum = 0;
            int indx;
            for (auto i = 0; i < k; ++i) {
                indx = i % n;
                sum += code[indx];
            }
            for (auto i = 0; i < n; ++i) {
                indx = (i + k) % n;
                sum -= code[i];
                sum += code[indx];
                res[i] = sum;
            }
        } else {
            k = 0 - k;
            reverse(code.begin(), code.end());
            int sum = 0;
            int indx;
            for (auto i = 0; i < k; ++i) {
                indx = i % n;
                sum += code[indx];
            }
            for (auto i = 0; i < n; ++i) {
                indx = (i + k) % n;
                sum -= code[i];
                sum += code[indx];
                res[i] = sum;
            }
            reverse(res.begin(), res.end());
        }
        return res;
    }
};
