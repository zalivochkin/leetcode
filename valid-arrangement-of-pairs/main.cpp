
class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> degr;
        for (const auto& pair : pairs) {
            adj[pair[0]].push_back(pair[1]);
            degr[pair[0]]++;
            degr[pair[1]]--;
        }
        int start_node = pairs[0][0];
        for (const auto [node, degree]: degr) {
            if (degree == 1) {
                start_node = node;
                break;
            }
        }
        vector<int> path;
        stack<int> st;
        st.push(start_node);
        int next_node;
        while (!st.empty()) {
            auto &neighbors = adj[st.top()];
            if (neighbors.empty()) {
                path.push_back(st.top());
                st.pop();
            } else {
                next_node = neighbors.back();
                st.push(next_node);
                neighbors.pop_back();
            }
        }
        const auto m = path.size();
        vector<vector<int>> res(m - 1);
        for (int i = m - 1; i > 0; --i) {
            res[m - i - 1] = {path[i], path[i - 1]};
        }
        return res;
    }
};
