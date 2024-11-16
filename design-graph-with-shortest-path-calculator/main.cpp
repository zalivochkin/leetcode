
class Solution {
public:
    Solution(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for (auto &edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
        costs.resize(n);
        completed.resize(n);
    }

    void addEdge(vector<int> edge) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
    }

    int shortestPath(int node1, int node2) {
        fill(costs.begin(), costs.end(), INT_MAX);
        fill(completed.begin(), completed.end(), 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> border;
        costs[node1] = 0;
        border.emplace(0, node1);
        int vertex_cost, vertex_index, new_cost;
        while (!border.empty()) {
            vertex_cost = border.top().first;
            vertex_index = border.top().second;
            if(vertex_index == node2) {
                break;
            }
            border.pop();
            if (completed[vertex_index] == 0) {
                for (auto [neighbor_index, neighbor_cost] : graph[vertex_index]) {
                    new_cost = vertex_cost + neighbor_cost;
                    if (new_cost < costs[neighbor_index]) {
                        costs[neighbor_index] = new_cost;
                        border.emplace(new_cost, neighbor_index);
                    }
                }
                completed[vertex_index] = 1;
            }
        }
        return costs[node2] == INT_MAX ? -1 : costs[node2];
    }

private:
    vector<vector<pair<int, int>>> graph;
    vector<int> costs;
    vector<int> completed;
};
