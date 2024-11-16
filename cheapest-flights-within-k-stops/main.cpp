
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto flight: flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }
        vector<int> prices(n, -1);
        queue<pair<int, int>> q;
        q.emplace(src, 0);
        ++k;
        int m;
        while(!q.empty()) {
            if(!k) {
                break;
            }
            m = q.size();
            for(auto i = 0; i < m; ++i) {
                auto [cur_city, cur_price] = q.front();
                q.pop();
                for(auto [neighbor_city, neighbor_price]: graph[cur_city]) {
                    if(prices[neighbor_city] == -1 || cur_price + neighbor_price < prices[neighbor_city]) {
                        prices[neighbor_city] = cur_price + neighbor_price;
                        q.emplace(neighbor_city, cur_price + neighbor_price);
                    }
                }
            }
            k--;
        }
        return prices[dst];
    }
};
