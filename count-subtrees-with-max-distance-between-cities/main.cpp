struct Node {
    vector<int> children;
};

struct SubTreeInfo {
    int depth, diameter;

    SubTreeInfo(int d, int dia) : depth(d), diameter(dia) {
    }
};

class Solution {
public:
    vector<SubTreeInfo> computeDiameters(vector<Node> &tree, int nodeIdx, vector<bool> &vis, vector<int> &res) {
        auto &node = tree[nodeIdx];
        vector<SubTreeInfo> subTrees{{0, 0}};
        vis[nodeIdx] = true;

        for (int childIdx: node.children) {
            if (vis[childIdx]) {
                continue;
            }
            int numSubTrees = subTrees.size();

            for (const auto &childSubTree: computeDiameters(tree, childIdx, vis, res)) {
                for (int i = 0; i < numSubTrees; ++i) {
                    auto &subTree = subTrees[i];
                    SubTreeInfo newSubTree(-1, -1);

                    newSubTree.depth = max(subTree.depth, 1 + childSubTree.depth);
                    newSubTree.diameter = max({
                        subTree.diameter, 1 + childSubTree.depth + subTree.depth, childSubTree.diameter
                    });

                    ++res[newSubTree.diameter - 1];
                    subTrees.emplace_back(newSubTree);
                }
            }
        }

        return subTrees;
    }

    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int> > &edges) {
        vector<int> res(n - 1);
        vector<Node> tree(n + 1);
        vector<bool> vis(n + 1);

        for (const auto &e: edges) {
            tree[e[0]].children.push_back(e[1]);
            tree[e[1]].children.push_back(e[0]);
        }

        computeDiameters(tree, 1, vis, res);
        return res;
    }
};
