
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> count('z' + 1, 0);
        int max_vowel = 0;
        int max_consonant = 0;
        for (const auto ch : s) {
            count[ch] += 1;
        }
        for (const auto ch : s) {
            if (isVowel(ch)) {
                max_vowel = max(max_vowel, count[ch]);
            } else {
                max_consonant = max(max_consonant, count[ch]);
            }
        }
        return max_vowel + max_consonant;
    }

private:
    static bool isVowel(char ch) {
        static const string kVowels = "aeiou";
        return kVowels.find(ch) != string::npos;
    }
};
