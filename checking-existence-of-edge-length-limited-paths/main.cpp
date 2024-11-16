
class Solution {
public:
    int findParent(vector<int> &parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        parent[node] = findParent(parent, parent[node]);
        return parent[node];
    }

    void unionNodes(vector<int> &parent, vector<int> &size, int node1, int node2) {
        node1 = findParent(parent, node1);
        node2 = findParent(parent, node2);
        if (node1 == node2) {
            return;
        }
        if (size[node1] > size[node2]) {
            parent[node2] = node1;
            size[node1] += size[node2];
        } else {
            parent[node1] = node2;
            size[node2] += size[node1];
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
        auto m = queries.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        vector<int> size(n, 1);
        for (auto i = 0; i < m; ++i) {
            queries[i].push_back(i);
        }
        vector<bool> ans(m, false);
        auto comparator = [](vector<int> &lft, vector<int> &rght) -> bool {
            return (lft[2] <= rght[2]);
        };
        sort(edgeList.begin(), edgeList.end(), comparator);
        sort(queries.begin(), queries.end(), comparator);
        for (auto i = 0, j = 0; i < m; ++i) {
            while (j < edgeList.size() && edgeList[j][2] < queries[i][2]) {
                unionNodes(parent, size, edgeList[j][0], edgeList[j][1]);
                ++j;
            }
            parent[queries[i][0]] = findParent(parent, queries[i][0]);
            parent[queries[i][1]] = findParent(parent, queries[i][1]);
            ans[queries[i][3]] = (parent[queries[i][0]] == parent[queries[i][1]]);
        }
        return ans;
    }
};
