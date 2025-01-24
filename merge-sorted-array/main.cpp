
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto nums2_pos = 0;
        for(auto i = 0; i < m + n; ++i) {
            if(nums2_pos < n && nums2[nums2_pos] <= nums1[i]) {
                nums1.insert(nums1.begin() + i, nums2[nums2_pos]);
                nums2_pos++;
                i--;
            }
        }
        nums1.resize(m + nums2_pos);
        for(auto i = nums2_pos; i < n; ++i) {
            nums1.push_back(nums2[i]);
        }
    }
};
