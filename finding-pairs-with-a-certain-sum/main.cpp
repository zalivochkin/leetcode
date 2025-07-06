
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1{nums1}, nums2{nums2} {
        for (auto num : nums2) {
            cnts[num] += 1;
        }
    }

    void add(int index, int val) {
        int old = nums2[index];
        cnts[old] -= 1;
        cnts[old + val] += 1;
        nums2[index] += val;
    }

    int count(int tot) {
        int ans = 0;
        for (auto num : nums1) {
            ans += cnts[tot - num];
        }
        return ans;
    }

private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> cnts;
};
