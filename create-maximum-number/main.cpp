
class comp {
public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        return p1.first == p2.first ? p1.second > p2.second : p1.first < p2.first;
    }
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            pq.emplace(nums[i], i);
            if (i >= nums.size() - k) {
                auto cur_pair = pq.top();
                pq.pop();
                ans.push_back(cur_pair.first);
                while (!pq.empty() && pq.top().second < cur_pair.second) {
                    pq.pop();
                }
            }
        }
        return ans;
    }

    vector<int> largestMerge(vector<int> &v1, vector<int> &v2) {
        auto n1 = v1.size();
        auto n2 = v2.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        while (i < n1 && j < n2) {
            if (v1[i] - v2[j] > 0) {
                ans.push_back(v1[i++]);
            } else if (v1[i] - v2[j] < 0) {
                ans.push_back(v2[j++]);
            } else {
                string s1(begin(v1) + i, end(v1));
                string s2(begin(v2) + j, end(v2));
                if (s1 > s2) {
                    ans.push_back(v1[i++]);
                } else {
                    ans.push_back(v2[j++]);
                }
            }
        }
        while (i < n1) {
            ans.push_back(v1[i++]);
        }
        while (j < n2) {
            ans.push_back(v2[j++]);
        }
        return ans;
    }

    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ans(k, 0);
        for (int i = 0; i <= k; i++) {
            if (i > nums1.size()) {
                break;
            }
            if (k - i > nums2.size()) {
                continue;
            }
            vector<int> v1 = mostCompetitive(nums1, i);
            vector<int> v2 = mostCompetitive(nums2, k - i);
            vector<int> v3 = largestMerge(v1, v2);
            string s1(begin(v3), end(v3));
            string s2(begin(ans), end(ans));
            if (s1 > s2) {
                ans = v3;
            }
        }
        return ans;
    }
};
