
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> dirs{{0,  -1}, {0,  1}, {-1, 0}, {1,  0}};
        vector<vector<int>> target{{1, 2, 3}, {4, 5, 0}};
        queue<pair<pair<int, int>, pair<vector<vector<int>>, int>>> q;
        for (auto i = 0; i < 2 && q.empty(); ++i) {
            for (auto j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    q.push({{i,     j}, {board, 0}});
                    break;
                }
            }
        }
        map<vector<vector<int>>, int> mp;
        mp[board]++;
        int row;
        int col;
        vector<vector<int>> v;
        int steps;
        int ti;
        int tj;
        while (!q.empty()) {
            row = q.front().first.first;
            col = q.front().first.second;
            v = q.front().second.first;
            steps = q.front().second.second;
            q.pop();
            if (v == target) {
                return steps;
            }
            for (auto i = 0; i < 4; ++i) {
                ti = row + dirs[i][0];
                tj = col + dirs[i][1];
                if (tj < 3 && ti < 2 && ti >= 0 && tj >= 0) {
                    swap(v[ti][tj], v[row][col]);
                    if (!mp.contains(v)) {
                        q.push({{ti, tj}, {v,  steps + 1}});
                        mp[v]++;
                    }
                    swap(v[ti][tj], v[row][col]);
                }
            }
        }
        return -1;
    }
};
