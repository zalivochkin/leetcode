
class Solution {
public:
    int numBusesToDestination(vector<vector<int> > &routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        int n = routes.size();
        unordered_map<int, unordered_set<int> > stop_to;
        for (int i = 0; i < n; ++i) {
            for (int stop: routes[i]) {
                stop_to[stop].insert(i);
            }
        }
        queue<pair<int, int> > q;
        unordered_set<int> visited;
        q.emplace(source, 0);
        visited.insert(source);
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                auto [cur_stop, changes] = q.front();
                q.pop();
                for (int route: stop_to[cur_stop]) {
                    for (int next: routes[route]) {
                        if (!visited.count(next)) {
                            if (next == target) {
                                return changes + 1;
                            }
                            visited.insert(next);
                            q.emplace(next, changes + 1);
                        }
                    }
                    routes[route].clear();
                }
            }
        }
        return -1;
    }
};
