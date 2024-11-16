
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind union_find(n);
        for (auto i = threshold + 1; i <= n; ++i) {
            if (!union_find.visited[i]) {
                for (auto j = i + i; j <= n; j += i) {
                    union_find.union_sets(i, j);
                }
            }
        }

        std::vector<bool> res;
        for (const auto& query : queries) {
            res.push_back(union_find.is_connected(query[0], query[1]));
        }
        return res;
    }
    
private:
    class UnionFind {
    public:
        explicit UnionFind(int n) : array(n + 1), visited(n + 1, false) {
            iota(array.begin(), array.end(), 0);
        }

        bool is_connected(int x, int y) {
            return parent(x) == parent(y);
        }

        void union_sets(int x, int y) {
            array[parent(y)] = parent(x);
            visited[x] = true;
            visited[y] = true;
        }

        std::vector<bool> visited;

protected:
        int parent(int v) {
            if (array[v] == v) {
                return v;
            }
            array[v] = parent(array[v]);
            return array[v];
        }

    private:
        std::vector<int> array;
    };
};
