
class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int res1 = 0;
        for (auto num : nums1) {
            if (find(nums2.begin(), nums2.end(), num) != nums2.end()) {
                ++res1;
            }
        }
        int res2 = 0;
        for (auto num : nums2) {
            if (find(nums1.begin(), nums1.end(), num) != nums1.end()) {
                ++res2;
            }
        }
        return {res1, res2};
    }
};
