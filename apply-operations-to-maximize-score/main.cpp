
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        const auto n = nums.size();
        vector<tuple<int, int, int>> arr(n);
        for (auto i = 0; i < n; ++i) {
            arr[i] = {i, primeFactors(nums[i]), nums[i]};
        }
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (auto [i, f, _] : arr) {
            while (!stk.empty() && get<1>(arr[stk.top()]) < f) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && get<1>(arr[stk.top()]) <= get<1>(arr[i])) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        ranges::sort(arr, [](const auto& lhs, const auto& rhs) {
            return get<2>(rhs) < get<2>(lhs);
        });
        long long ans = 1;
        for (auto [i, _, x] : arr) {
            int l = left[i];
            int r = right[i];
            long long cnt = 1LL * (i - l) * (r - i);
            if (cnt <= k) {
                ans = ans * qpow(x, cnt) % mod;
                k -= cnt;
            } else {
                ans = ans * qpow(x, k) % mod;
                break;
            }
        }
        return ans;
    }

    long long qpow(long long a, int n) {
        const int mod = 1e9 + 7;
        long long ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            n >>= 1;
        }
        return ans;
    }

    int primeFactors(int n) {
        int i = 2;
        unordered_set<int> ans;
        while (i <= n / i) {
            while (n % i == 0) {
                ans.insert(i);
                n /= i;
            }
            ++i;
        }
        if (n > 1) {
            ans.insert(n);
        }
        return ans.size();
    }
};
