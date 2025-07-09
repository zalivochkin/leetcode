
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        const vector<int> gaps = getGaps(eventTime, startTime, endTime);
        int windowSum = accumulate(gaps.begin(), gaps.begin() + k + 1, 0);
        int ans = windowSum;
        const auto n = gaps.size();
        for (auto i = k + 1; i < n; ++i) {
            windowSum += gaps[i] - gaps[i - k - 1];
            ans = max(ans, windowSum);
        }
        return ans;
    }

private:
    static vector<int> getGaps(int eventTime, const vector<int>& startTime, const vector<int>& endTime) {
        vector<int> gaps{startTime[0]};
        const auto n = startTime.size();
        for (auto i = 1; i < n; ++i) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        gaps.push_back(eventTime - endTime.back());
        return gaps;
    }
};
