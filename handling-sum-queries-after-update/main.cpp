
class Solution {
public:
    void build(vector<long long> &sum_tree, vector<int> &nums, int tree_indx, int l, int r) {
        if (l == r) {
            sum_tree[tree_indx] = nums[l];
        } else {
            int mid = l + (r - l) / 2;
            build(sum_tree, nums, tree_indx * 2, l, mid);
            build(sum_tree, nums, tree_indx * 2 + 1, mid + 1, r);
            sum_tree[tree_indx] = sum_tree[tree_indx * 2] + sum_tree[tree_indx * 2 + 1];
        }
    }
    
    void push(vector<long long> &sum_tree, vector<bool> &marked, int tree_indx, int tl, int tr) {
        if (marked[tree_indx]) {
            int mid = tl + (tr - tl) / 2;
            sum_tree[tree_indx * 2] = mid - tl + 1 - sum_tree[tree_indx * 2];
            sum_tree[tree_indx * 2 + 1] = tr - (mid + 1) + 1 - sum_tree[tree_indx * 2 + 1];
            marked[tree_indx * 2] = !marked[tree_indx * 2];
            marked[tree_indx * 2 + 1] = !marked[tree_indx * 2 + 1];
            bool lazy = marked[tree_indx * 2];
            lazy ^= true;
            marked[tree_indx * 2] = lazy;
            lazy = marked[tree_indx * 2 + 1];
            lazy ^= true;
            marked[tree_indx * 2 + 1] = lazy;
            marked[tree_indx] = false;
        }
    }

    void flip(vector<long long> &sum_tree, vector<bool> &marked, int tree_indx, int tl, int tr, int l, int r) {
        if (l > r) {
            return;
        }
        if (tl == l and tr == r) {
            sum_tree[tree_indx] = tr - tl + 1 - sum_tree[tree_indx];
            marked[tree_indx] = !marked[tree_indx];
        } else {
            push(sum_tree, marked, tree_indx, tl, tr);
            int mid = tl + (tr - tl) / 2;
            flip(sum_tree, marked, tree_indx * 2, tl, mid, l, min(r, mid));
            flip(sum_tree, marked, tree_indx * 2 + 1, mid + 1, tr, max(l, mid + 1), r);
            sum_tree[tree_indx] = sum_tree[tree_indx * 2] + sum_tree[tree_indx * 2 + 1];
        }
    }

    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> res;
        auto n = nums1.size();
        vector<long long> sum_tree(n * 4, 0L);
        vector<bool> marked(n * 4, false);
        build(sum_tree, nums1, 1, 0, n - 1);
        long long cur_sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        for (const auto &querie : queries) {
            if (querie[0] == 1) {
                flip(sum_tree, marked, 1, 0, n - 1, querie[1], querie[2]);
            } else if (querie[0] == 2) {
                cur_sum += sum_tree[1] * static_cast<long long>(querie[1]);
            } else if (querie[0] == 3) {
                res.push_back(cur_sum);
            }
        }
        return res;
    }
};
