
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        const auto n = status.size();
        vector<bool> has(n);
        vector<bool> took(n);
        queue<int> q;
        for (auto i : initialBoxes) {
            has[i] = true;
            if (status[i]) {
                ans += candies[i];
                took[i] = true;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto k : keys[i]) {
                status[k] = 1;
                if (has[k] && !took[k]) {
                    ans += candies[k];
                    took[k] = true;
                    q.push(k);
                }
            }
            for (auto j : containedBoxes[i]) {
                has[j] = true;
                if (status[j] && !took[j]) {
                    ans += candies[j];
                    took[j] = true;
                    q.push(j);
                }
            }
        }
        return ans;
    }
};
