
class Solution {
public:
    long long count(vector<int>& nums1, vector<int>& nums2, long long p) {
        long long cnt = 0;
        const auto m = nums2.size();
        for (int num : nums1) {
            if (num > 0) {
                int l = 0;
                int r = m;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (1LL * num * nums2[mid] > p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += l;
            } else if (num < 0) {
                int l = 0;
                int r = m;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (1LL * num * nums2[mid] <= p) {
                        r = mid;
                    } else {
                        l = mid + 1;
                    }
                }
                cnt += m - l;
            } else if (p >= 0) {
                cnt += m;
            }
        }
        return cnt;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        const auto n = nums1.size();
        const auto m = nums2.size();
        int a = max(abs(nums1[0]), abs(nums1[n - 1]));
        int b = max(abs(nums2[0]), abs(nums2[m - 1]));
        long long r = 1LL * a * b;
        long long l = -r;
        while (l < r) {
            long long mid = (l + r) >> 1;
            if (count(nums1, nums2, mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
