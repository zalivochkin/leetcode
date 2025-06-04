
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.length();
        string res = "";
        for (int i = 0; i < n; ++i) {
            string s = word.substr(i, min(i + n - numFriends + 1, n) - i);
            if (res.compare(s) <= 0) {
                res = s;
            }
        }
        return res;
    }
};
