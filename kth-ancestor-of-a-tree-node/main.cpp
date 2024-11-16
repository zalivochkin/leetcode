
struct Node {
    explicit Node(int value_) : value{value_} {};
    int value;
    vector<Node> children;
};

class TreeAncestor {
public:
    TreeAncestor(int n, vector<int> &parent) : P(20, vector<int>(parent.size(), -1)) {
        for (int i = 0; i < parent.size(); i++) {
            P[0][i] = parent[i];
        }
        for (int i = 1; i < 20; i++) {
            for (int node = 0; node < parent.size(); node++) {
                int nodep = P[i - 1][node];
                if (nodep != -1) {
                    P[i][node] = P[i - 1][nodep];
                }
            }
        }
    }
    int getKthAncestor(int node, int k) {
        for (int i = 19; i >= 0; i--) {
            int num = pow(2, i);
            if (k >= num) {
                node = P[i][node];
                k -= num;
                if (node == -1) {
                    return -1;
                }
            }
        }

        return node;
    }
    vector<vector<int>> P;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
