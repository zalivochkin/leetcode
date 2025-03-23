
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long inf = numeric_limits<long long>::max() / 2;
        const int mod = 1e9 + 7;

        vector<vector<long long>> graph(n, vector<long long>(n, inf));
        for (auto &edge : graph) {
            ranges::fill(edge, inf);
        }

        for (const auto &road : roads) {
            graph[road[0]][road[1]] = road[2];
            graph[road[1]][road[0]] = road[2];
        }

        graph[0][0] = 0;

        vector<long long> dist(n, inf);
        ranges::fill(dist, inf);
        dist[0] = 0;

        vector<long long> dp(n);
        dp[0] = 1;

        vector<bool> visited(n, false);
        for (auto i = 0; i < n; ++i) {
            int t = -1;
            for (auto j = 0; j < n; ++j) {
                if (!visited[j] && (t == -1 || dist[j] < dist[t])) {
                    t = j;
                }
            }
            visited[t] = true;
            for (auto j = 0; j < n; ++j) {
                if (j == t) {
                    continue;
                }
                long long ne = dist[t] + graph[t][j];
                if (dist[j] > ne) {
                    dist[j] = ne;
                    dp[j] = dp[t];
                } else if (dist[j] == ne) {
                    dp[j] = (dp[j] + dp[t]) % mod;
                }
            }
        }
        return (int) dp[n - 1];
    }
};
