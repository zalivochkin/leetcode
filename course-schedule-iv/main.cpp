
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
        for (const auto& prereq : prerequisites) {
            isReachable[prereq[0]][prereq[1]] = true;
        }
        for (auto i = 0; i < numCourses; i++) {
            for (auto j = 0; j < numCourses; j++) {
                for (auto k = 0; k < numCourses; k++) {
                    if (isReachable[j][i] && isReachable[i][k]) {
                        isReachable[j][k] = true;
                    }
                }
            }
        }
        vector<bool> res;
        for (const auto &query : queries) {
            res.push_back(isReachable[query[0]][query[1]]);
        }
        return res;
    }
};
