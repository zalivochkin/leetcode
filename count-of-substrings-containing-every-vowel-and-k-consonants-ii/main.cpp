
class Solution {
public:
    inline bool is_vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long fn(const string &word, int k) {
        long long ans = 0;
        int lft = 0;
        int non_vowels = 0;
        unordered_map<char, int> cnt;
        for (auto ch : word) {
            if (is_vowel(ch)) {
                cnt[ch] += 1;
            } else {
                ++non_vowels;
            }
            while (non_vowels >= k && cnt.size() == 5) {
                char d = word[lft];
                ++lft;
                if (is_vowel(d)) {
                    cnt[d] -= 1;
                    if (cnt[d] == 0) {
                        cnt.erase(d);
                    }
                } else {
                    --non_vowels;
                }
            }
            ans += lft;
        }
        return ans;
    }

    long long countOfSubstrings(string word, int k) {
        return fn(word, k) - fn(word, k + 1);
    }
};
