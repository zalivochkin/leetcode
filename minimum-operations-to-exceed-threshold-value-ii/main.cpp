
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (const auto num : nums) {
            pq.push(num);
        }
        int ops = 0;
        while (pq.size() > 1 && pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            ++ops;
        }
        return ops;
    }
};
