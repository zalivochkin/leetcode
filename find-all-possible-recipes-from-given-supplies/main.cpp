
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        const auto n = recipes.size();
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indeg;
        for (auto i = 0; i < n; ++i) {
            for (const auto &ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
            }
            indeg[recipes[i]] = ingredients[i].size();
        }
        queue<string> q;
        for (const auto &supply : supplies) {
            q.push(supply);
        }
        vector<string> ans;
        while (!q.empty()) {
            for (int n = q.size(); n > 0; --n) {
                const auto supply1 = q.front();
                q.pop();
                for (const auto &supply2 : graph[supply1]) {
                    indeg[supply2] -= 1;
                    if (indeg[supply2] == 0) {
                        ans.push_back(supply2);
                        q.push(supply2);
                    }
                }
            }
        }
        return ans;
    }
};
