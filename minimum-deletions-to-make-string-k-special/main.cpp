
class Solution {
public:
    int f(vector<int> &nums, int v, int k) {
        int ans = 0;
        for (auto num : nums) {
            if (num < v) {
                ans += num;
            } else if (num > v + k) {
                ans += num - v - k;
            }
        }
        return ans;
    }

    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (auto ch : word) {
            freq[ch - 'a'] += 1;
        }
        vector<int> nums;
        for (auto v : freq) {
            if (v) {
                nums.push_back(v);
            }
        }
        const auto n = word.size();
        int ans = n;
        for (int i = 0; i <= n; ++i) {
            ans = min(ans, f(nums, i, k));
        }
        return ans;
    }
};
