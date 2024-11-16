
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int> > &queries) {
        int n = heights.size();
        vector<int> rm(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] <= heights[i]) {
                s.pop();
            }
            if (!s.empty()) {
                rm[i] = s.top();
            }
            s.push(i);
        }
        int q = queries.size();
        vector<int> ans(q, -1);
        for (int i = 0; i < q; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (y > x) {
                swap(x, y);
            }
            if (x == y) {
                ans[i] = x;
            } else if (x > y) {
                if (heights[x] > heights[y]) {
                    ans[i] = x;
                } else {
                    if (rm[y] == -1) {
                        ans[i] = -1;
                    } else {
                        int p = rm[x];
                        while (p != -1 && heights[p] <= heights[y]) {
                            p = rm[p];
                        }
                        ans[i] = p;
                    }
                }
            }
        }

        return ans;
    }
};
