class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (visited.contains(node)) {
            return visited[node];
        }
        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (auto &neighbor_node : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor_node));
        }
        return clone;
    }
};
