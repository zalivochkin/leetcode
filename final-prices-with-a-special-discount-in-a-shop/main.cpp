
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        const auto n = prices.size();
        for (auto i = 0; i < n; ++i) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};
