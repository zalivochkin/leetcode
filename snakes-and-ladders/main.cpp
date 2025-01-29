
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        const auto n = board.size();
        const auto m = n * n;
        vector<bool> visited(m + 1, false);
        visited[1] = true;
        queue<int> q;
        q.push(1);
        int res = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                int lbl = q.front();
                q.pop();
                if (lbl == m) {
                    return res;
                }
                for (int j = lbl + 1; j <= min(lbl + 6, static_cast<int>(m)); ++j) {
                    int integ = (j - 1) / n;
                    int reminder = (j - 1) % n;
                    if (integ % 2 == 1) {
                        reminder = n - reminder - 1;
                    }
                    integ = n - integ - 1;
                    int target_lbl = j;
                    if (board[integ][reminder] != -1) {
                        target_lbl = board[integ][reminder];
                    }
                    if (!visited[target_lbl]) {
                        visited[target_lbl] = true;
                        q.push(target_lbl);
                    }
                }
                --sz;
            }
            ++res;
        }
        return -1;
    }
};
