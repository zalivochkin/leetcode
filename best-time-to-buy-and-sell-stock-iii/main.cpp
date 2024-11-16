
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        vector<int> first_trade_profit(prices.size(), 0);
        int min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            min_price = min(min_price, prices[i]);
            first_trade_profit[i] = max(first_trade_profit[i - 1], prices[i] - min_price);
        }
        vector<int> second_trade_profit(prices.size(), 0);
        min_price = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            min_price = min(min_price, prices[i] - first_trade_profit[i - 1]);
            second_trade_profit[i] = max(second_trade_profit[i - 1], prices[i] - min_price);
        }
        return second_trade_profit[prices.size() - 1];
    }
};
