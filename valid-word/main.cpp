
class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool has_vowel = false;
        bool has_consonant = false;
        vector<bool> vs(26 + 'a', false);
        string vowels = "aeiou";
        for (auto ch : vowels) {
            vs[ch] = true;
        }
        for (auto ch : word) {
            if (isalpha(ch)) {
                if (vs[tolower(ch)]) {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if (!isdigit(ch)) {
                return false;
            }
        }
        return has_vowel && has_consonant;
    }
};
