
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        return max(maxCycle(favorite), topologicalSort(favorite));
    }

    int maxCycle(vector<int>& favorite) {
        const auto n = favorite.size();
        vector<bool> visited(n);
        int res = 0;
        int j;
        for (auto i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> cycle;
                j = i;
                while (!visited[j]) {
                    cycle.push_back(j);
                    visited[j] = true;
                    j = favorite[j];
                }
                for (auto k = 0; k < cycle.size(); ++k) {
                    if (cycle[k] == j) {
                        res = max(res, (int) cycle.size() - k);
                        break;
                    }
                }
            }
        }
        return res;
    }

    int topologicalSort(vector<int>& favorite) {
        const auto n = favorite.size();
        vector<int> indeg(n);
        vector<int> dist(n, 1);
        for (auto fav : favorite) {
            indeg[fav] += 1;
        }
        queue<int> q;
        for (auto i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int i;
        while (!q.empty()) {
            i = q.front();
            q.pop();
            dist[favorite[i]] = max(dist[favorite[i]], dist[i] + 1);
            indeg[favorite[i]] -= 1;
            if (indeg[favorite[i]] == 0) {
                q.push(favorite[i]);
            }
        }
        int res = 0;
        for (i = 0; i < n; ++i) {
            if (i == favorite[favorite[i]]) {
                res += dist[i];
            }
        }
        return res;
    }
};
