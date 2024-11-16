
// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
public:
    int get(int index) {
        return vec[index];
    }
    int length() {
        return vec.size();
    }
private:
    const vector<int> vec1{1,2,3,4,5,3,1}; // 2
    const vector<int> vec{3,5,3,2,0}; // 4
};

class Solution {
public:
    inline int cachedGet(MountainArray &mountainArr, int indx, unordered_map<int, int> &mem) const {
        if (mem.contains(indx)) {
            return mem[indx];
        }
        mem[indx] = mountainArr.get(indx);
        return mem[indx];
    }
    
    inline int findTop(const size_t n, MountainArray &mountainArr, unordered_map<int, int> mem) const {
        int left = 1;
        int right = n - 2;
        int mid;
        int mid_val, mid_prev_val;
        while (right - left > 1) {
            mid = left + (right - left) / 2;
            mid_val = cachedGet(mountainArr, mid, mem);
            mid_prev_val = cachedGet(mountainArr, mid - 1, mem);
            if (mid_val > mid_prev_val) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (cachedGet(mountainArr, left, mem) > cachedGet(mountainArr, right, mem)) {
            return left;
        }
        return right;
    }

    int findInRange(int start_indx, int end_indx, const int target, MountainArray &mountainArr, const int dir, unordered_map<int, int> &mem) const {
        int left_val = cachedGet(mountainArr, start_indx, mem);
        if (left_val == target) {
            return start_indx;
        }
        int right_val = cachedGet(mountainArr, end_indx, mem);
        if (right_val == target) {
            return end_indx;
        }
        int mid;
        int mid_val;
        while (end_indx - start_indx > 1) {
            mid = start_indx + (end_indx - start_indx) / 2;
            mid_val = cachedGet(mountainArr, mid, mem);
            if (mid_val == target) {
                return mid;
            }
            if (dir == 1) {
                if (mid_val < target) {
                    start_indx = mid;
                } else {
                    end_indx = mid;
                }
            } else {
                if (mid_val > target) {
                    start_indx = mid;
                } else {
                    end_indx = mid;
                }
            }
        }
        right_val = cachedGet(mountainArr, end_indx, mem);
        if (right_val == target) {
            return end_indx;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        auto n = mountainArr.length();
        unordered_map<int, int> mem;
        int top_index = findTop(n, mountainArr, mem);
        int top_val = cachedGet(mountainArr, top_index, mem);
        if (top_val < target) {
            return -1;
        }
        int res = findInRange(0, top_index, target, mountainArr, 1, mem);
        if (res == -1) {
            return findInRange(top_index, n - 1, target, mountainArr, -1, mem);
        }
        return res;
    }
};
