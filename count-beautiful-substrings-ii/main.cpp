
class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        auto n = s.size();
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

        int mod;
        for (mod = 1; mod * mod % k != 0; ++mod) {}

        int res = 0;
        unordered_map<int, unordered_map<int, int>> m{{0, {{0, 1}}}};
        for (int i = 0, vowels_counter = 0; i < n; ++i) {
            if (vowels.contains(s[i])) {
                ++vowels_counter;
            }
            res += m[2 * vowels_counter - i - 1][vowels_counter % mod];
            m[2 * vowels_counter - i - 1][vowels_counter % mod]++;
        }
        return res;
    }
};
