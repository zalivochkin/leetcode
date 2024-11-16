
class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        array<array<int, 100>, 201> reachable{0};
        reachable[fuel][start] = 1;
        for (; fuel > 0; fuel--) {
            for (start = 0; start < n; ++start) {
                if (reachable[fuel][start] > 0) {
                    for (int location = 0; location < n; ++location) {
                        if (location != start) {
                            int new_fuel = fuel - abs(locations[start] - locations[location]);
                            if (new_fuel < 0) {
                                continue;
                            }
                            int ways_to_reach = reachable[new_fuel][location];
                            ways_to_reach += reachable[fuel][start];
                            ways_to_reach %= mod;
                            reachable[new_fuel][location] = ways_to_reach;
                        }
                    }
                }
            }
        }
        int sum = 0;
        for (auto x: reachable) {
            sum += x[finish];
            sum %= mod;
        }
        return sum;
    }
};
