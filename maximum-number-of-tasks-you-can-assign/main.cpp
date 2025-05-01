
class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int x) {
        int p = pills;
        deque<int> dq;
        int i = 0;
        const auto m = workers.size();
        for (auto j = m - x; j < m; ++j) {
            while (i < x && tasks[i] <= workers[j] + strength) {
                dq.push_back(tasks[i++]);
            }
            if (dq.empty()) {
                return false;
            }
            if (dq.front() <= workers[j]) {
                dq.pop_front();
            } else if (p == 0) {
                return false;
            } else {
                --p;
                dq.pop_back();
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        ranges::sort(tasks);
        ranges::sort(workers);
        const auto n = tasks.size();
        const auto m = workers.size();
        int left = 0;
        int right = min(m, n);
        while (left < right) {
            int mid = midpoint(left, right + 1);
            if (check(tasks, workers, pills, strength, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
