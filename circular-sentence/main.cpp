
class Solution {
public:
    bool isCircularSentence(string sentence) {
        const auto n = sentence.size();
        if (n == 1) {
            return true;
        }
        const auto first_ch = sentence[0];
        const auto last_ch = sentence.back();
        if (first_ch != last_ch) {
            return false;
        }
        for (auto i = 0; i < n; ++i) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
