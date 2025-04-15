
class Solution {
    class BinaryIndexedTree {
        private final int n;
        private final int[] c;

        public BinaryIndexedTree(int n) {
            this.n = n;
            c = new int[n + 1];
        }

        public void update(int x, int delta) {
            while (x <= n) {
                c[x] += delta;
                x += lowbit(x);
            }
        }

        public int query(int x) {
            int s = 0;
            while (x > 0) {
                s += c[x];
                x -= lowbit(x);
            }
            return s;
        }

        public static int lowbit(int x) {
            return x & -x;
        }
    }
    public long goodTriplets(int[] nums1, int[] nums2) {
        final var n = nums1.length;
        int[] pos = new int[n];
        BinaryIndexedTree tree = new BinaryIndexedTree(n);
        for (var i = 0; i < n; ++i) {
            pos[nums2[i]] = i + 1;
        }
        long ans = 0;
        for (var num : nums1) {
            int p = pos[num];
            long left = tree.query(p);
            long right = n - p - (tree.query(n) - tree.query(p));
            ans += left * right;
            tree.update(p, 1);
        }
        return ans;
    }
}
