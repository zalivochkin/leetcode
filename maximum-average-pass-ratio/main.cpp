
class Solution {
public:
    class Comp {
    public:
        bool operator()(const vector<double> &a, const vector<double> &b) const {
            return a[0] < b[0];
        } 
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>, vector<vector<double>>, Comp> pq;
        for (auto clas : classes) {
            double ret = static_cast<double>(clas[0]) / static_cast<double>(clas[1]);
            double new_ret = static_cast<double>(clas[0] + 1) / static_cast<double>(clas[1] + 1);
            pq.push(vector<double>{new_ret - ret, static_cast<double>(clas[0]), static_cast<double>(clas[1])});
        }
        for (auto i = 0; i < extraStudents; ++i) {
            auto clas = pq.top();
            pq.pop();
            clas[1] += 1;
            clas[2] += 1;
            double ret = clas[1] / clas[2];
            double new_ret = (clas[1] + 1.0) / (clas[2] + 1.0);
            pq.push(vector<double>{new_ret - ret, clas[1], clas[2]});
        }
        double ans = 0.0;
        while (!pq.empty()) {
            const auto &clas = pq.top();
            ans += clas[1] / clas[2];
            pq.pop();
        }
        return ans / static_cast<double>(classes.size());
    }
};
