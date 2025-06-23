
class Solution {
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        for (int l = 1;; ++l) {
            int x = pow(10, (l - 1) / 2);
            int y = pow(10, (l + 1) / 2);
            for (int i = x; i < y; ++i) {
                long long v = i;
                for (int j = (l % 2 == 0 ? i : i / 10); j > 0; j /= 10) {
                    v = v * 10 + j % 10;
                }
                string s = toBase(v, k);
                if (isPalindrome(s)) {
                    ans += v;
                    if (--n == 0) {
                        return ans;
                    }
                }
            }
        }
    }
private:
    // Преобразование числа в строку в системе счисления base
    string toBase(long long num, int base) {
        string result;
        do {
            int digit = num % base;
            result += (digit < 10 ? '0' + digit : 'a' + digit - 10);
            num /= base;
        } while (num > 0);
        reverse(result.begin(), result.end());
        return result;
    }

    // Проверка на палиндром
    bool isPalindrome(const std::string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
