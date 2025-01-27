
import java.util.*;

class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        List<List<Boolean>> isReachable = new ArrayList<>(numCourses);
        for (var i = 0; i < numCourses; i++) {
            isReachable.add(new ArrayList<>(Collections.nCopies(numCourses, false)));
        }
        for (var prereq : prerequisites) {
            isReachable.get(prereq[0]).set(prereq[1], true);
        }
        for (var i = 0; i < numCourses; i++) {
            for (var j = 0; j < numCourses; j++) {
                for (var k = 0; k < numCourses; k++) {
                    if (isReachable.get(j).get(i) && isReachable.get(i).get(k)) {
                        isReachable.get(j).set(k, true);
                    }
                }
            }
        }
        List<Boolean> res = new ArrayList<>(queries.length);
        for (int[] query : queries) {
            res.add(isReachable.get(query[0]).get(query[1]));
        }
        return res;
    }
}
