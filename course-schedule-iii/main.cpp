
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](const vector<int> &c1, const vector<int> &c2) -> bool { return c1[1] < c2[1]; });
        auto n = courses.size();
        priority_queue<int> pq;
        int sum_time = 0;
        for(auto i = 0; i < n; ++i) {
            sum_time += courses[i][0];
            pq.push(courses[i][0]);
            if(sum_time > courses[i][1]) {
                sum_time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
