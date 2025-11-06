
using pii = pair<int,int>;

class Solution {
public:
    vector<vector<int>> graph;                     // adjacency list
    vector<int> stationToGrid;                     // maps station -> gridId
    vector<set<pii>> powerGrids;                   // one set per grid (status,id)
    vector<bool> visited;                          // for DFS

    // DFS to collect all stations in a grid
    void dfs(int station, set<pii>& gridSet, int gridId) {
        visited[station] = true;
        stationToGrid[station] = gridId;
        gridSet.insert({1, station}); // (1 => online, station id)

        for (int neighbor : graph[station]) {
            if (!visited[neighbor])
                dfs(neighbor, gridSet, gridId);
        }
    }

    vector<int> processQueries(
            int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
    {
        graph.assign(c + 1, {});
        visited.assign(c + 1, false);
        stationToGrid.resize(c + 1);

        // Step 1: Build graph
        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // Step 2: Identify all connected components (power grids)
        int gridId = 0;
        for (int s = 1; s <= c; ++s) {
            if (!visited[s]) {
                set<pii> gridSet;
                dfs(s, gridSet, gridId);
                powerGrids.push_back(gridSet);
                gridId++;
            }
        }

        // Step 3: Process queries
        vector<int> result;

        for (auto& q : queries) {
            int type = q[0], station = q[1];
            int gridId = stationToGrid[station];

            if (type == 1) {
                // Maintenance check
                if (powerGrids[gridId].count({1, station})) {
                    // Station itself is online
                    result.push_back(station);
                } else {
                    // Get smallest online station in same grid
                    auto it = powerGrids[gridId].begin();
                    if (it->first == 1)
                        result.push_back(it->second);
                    else
                        result.push_back(-1);
                }
            }
            else if (type == 2) {
                // Station goes offline
                if (powerGrids[gridId].count({1, station})) {
                    powerGrids[gridId].erase({1, station});
                    powerGrids[gridId].insert({2, station});
                }
            }
        }

        return result;
    }
};
