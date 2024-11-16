
class Solution {
public:
    int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices) {
        long long m = changeIndices.size();
        long long n = nums.size();
        vector<int> changeIndicesSelected;
        set<int> tmp;
        for (int i = 0; i < m; ++i) {
            if (nums[changeIndices[i] - 1] > 1 && !tmp.contains(changeIndices[i])) {
                tmp.insert(changeIndices[i]);
                changeIndicesSelected.push_back(i);
            }
        }
        auto maxSeconds = accumulate(nums.begin(), nums.end(), 0LL) + n;
        auto lft = n - 1;
        auto minMax = min(maxSeconds, m);
        auto rght = minMax + 2;
        while (rght - lft > 1) {
            auto mid = lft + (rght - lft) / 2;
            if (isGood(nums, changeIndices, n, mid)) {
                rght = mid;
            } else {
                lft = mid;
            }
        }
        return rght > minMax ? -1 : rght;
    }

    bool isGood(const vector<int> &nums, const vector<int> &changeIndices, long long n, long long ans) {
        if (ans == changeIndices.size() + 1) {
            return true;
        }

        vector<bool> seen(n);
        vector<pair<int, int>> ps;
        for (int j = 0; j < ans; ++j) {
            if (!seen[changeIndices[j] - 1]) {
                seen[changeIndices[j] - 1] = true;
                ps.emplace_back(j, changeIndices[j] - 1);
            }
        }
        long long k = static_cast<long long>(ps.size()) - 1;

        int remaining = 0;
        priority_queue<pair<int, int>> pq;
        for (long long j = ans - 1; j >= 0; --j) {
            if (k >= 0 && ps[k].first == j) {
                if (nums[ps[k].second] > 0) {
                    pq.emplace(-nums[ps[k].second], ps[k].second);
                } else {
                    ++remaining;
                }
                --k;
            } else {
                ++remaining;
            }
            while (remaining < pq.size()) {
                pq.pop();
                ++remaining;
            }
        }

        long long needops = n;
        vector<int> cnt = nums;
        while (!pq.empty()) {
            auto [negcnt, i] = pq.top();
            pq.pop();
            cnt[i] = 0;
            needops++;
        }
        needops += accumulate(cnt.begin(), cnt.end(), 0LL);
        return needops <= (long long) ans;
    }
};
