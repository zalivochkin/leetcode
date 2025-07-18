
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        const auto m = nums.size();
        int n = m / 3;
        long long s = 0;
        vector<long long> pre(m + 1, 0);
        priority_queue<int> q1;
        for (auto i = 1; i <= n * 2; ++i) {
            int x = nums[i - 1];
            s += x;
            q1.push(x);
            if (q1.size() > n) {
                s -= q1.top();
                q1.pop();
            }
            pre[i] = s;
        }
        s = 0;
        vector<long long> suf(m + 1, 0);
        priority_queue<int, vector<int>, greater<>> q2;
        for (int i = m; i > n; --i) {
            int x = nums[i - 1];
            s += x;
            q2.push(x);
            if (q2.size() > n) {
                s -= q2.top();
                q2.pop();
            }
            suf[i] = s;
        }
        long long ans = 1e18;
        for (auto i = n; i <= n * 2; ++i) {
            ans = min(ans, pre[i] - suf[i + 1]);
        }
        return ans;
    }
};
