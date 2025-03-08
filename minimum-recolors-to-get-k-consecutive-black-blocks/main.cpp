
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        const auto n = blocks.size();
        int cnt = count(blocks.begin(), blocks.begin() + k, 'W');
        int ans = cnt;
        for (auto i = k; i < n; ++i) {
            if (blocks[i] == 'W') {
                ++cnt;
            }
            if (blocks[i - k] == 'W') {
                --cnt;
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};
