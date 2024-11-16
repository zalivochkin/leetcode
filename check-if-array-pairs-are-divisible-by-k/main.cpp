
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        auto n = arr.size();
        vector<int> freq(k, 0);
        for (auto i = 0; i < n; ++i) {
            freq[((arr[i] % k) + k) % k] += 1;
        }
        if (freq[0] % 2 != 0) {
            return false;
        }
        for (auto i = 1; i <= k / 2; ++i) {
            if (freq[i] != freq[k - i]) {
                return false;
            }
        }
        return true;
    }
};
