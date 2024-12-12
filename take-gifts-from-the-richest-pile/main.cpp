
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long total_gifts = 0LL;
        for (const auto gift : gifts) {
            pq.push(gift);
            total_gifts += gift;
        }
        for  (auto i = 0; i < k; ++i) {
            auto gift = pq.top();
            pq.pop();
            auto new_gift = static_cast<int>(floor(sqrt(gift)));
            pq.push(new_gift);
            total_gifts -= gift - new_gift;
        }
        return total_gifts;
    }
};
