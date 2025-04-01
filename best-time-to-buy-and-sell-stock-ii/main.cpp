
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        const auto n = prices.size();
        for (auto i = 1; i < n; ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
