
class Solution {
public:
    int calc_height(int start, unordered_map<int, unordered_set<int>> &map_edges, vector<bool> visited) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        int height = 0;
        while (!q.empty()) {
            auto n = q.size();
            for (auto i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                for (auto &neighbor: map_edges[node]) {
                    if (!visited[neighbor]) {
                        q.push(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
            height++;
        }
        return height;
    }

    int check_connected_bfs(int start, unordered_map<int, unordered_set<int>> &map_edges, vector<bool> &visited) {
        vector<int> members;
        vector<bool> orig_visited = visited;
        queue<int> q;
        q.push(start);
        members.push_back(start);
        visited[start] = true;

        int height = 0;
        while (!q.empty()) {
            auto n = q.size();
            vector<int> all_linked_nodes;
            for (auto i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();
                for (auto &linked_node: map_edges[node]) {
                    if (!visited[linked_node]) {
                        all_linked_nodes.push_back(linked_node);
                        visited[linked_node] = true;
                    }
                }
            }
            auto m = all_linked_nodes.size();
            for (auto i = 0; i < m; ++i) {
                for (auto j = 0; j < i; ++j) {
                    if (map_edges[all_linked_nodes[i]].count(all_linked_nodes[j])) {
                        return -1;
                    }
                }
            }
            for (auto i = 0; i < m; ++i) {
                q.push(all_linked_nodes[i]);
                members.push_back(all_linked_nodes[i]);
            }
            height++;
        }
        for (auto &member: members) {
            height = max(height, calc_height(member, map_edges, orig_visited));
        }
        return height;
    }

    int magnificentSets(int n, vector<vector<int>> &edges) {
        unordered_map<int, unordered_set<int>> map_edges;
        for (auto &edge: edges) {
            map_edges[edge[0] - 1].insert(edge[1] - 1);
            map_edges[edge[1] - 1].insert(edge[0] - 1);
        }
        vector<bool> visited(n, false);
        int total_height = 0;
        for (auto node = 0; node < n; ++node) {
            if (!visited[node]) {
                int height = check_connected_bfs(node, map_edges, visited);
                if (height == -1) {
                    return -1;
                }
                total_height += height;
            }
        }
        return total_height;
    }

};
