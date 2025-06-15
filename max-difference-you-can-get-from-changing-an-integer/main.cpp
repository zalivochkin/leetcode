
class Solution {
public:
    void replace(string& s, char a, char b) {
        for (auto& c : s) {
            if (c == a) {
                c = b;
            }
        }
    }

    int maxDiff(int num) {
        string a = to_string(num);
        string b = a;
        const auto n = a.size();
        for (int i = 0; i < n; ++i) {
            if (a[i] != '9') {
                replace(a, a[i], '9');
                break;
            }
        }
        if (b[0] != '1') {
            replace(b, b[0], '1');
        } else {
            const auto m = b.size();
            for (int i = 1; i < m; ++i) {
                if (b[i] != '0' && b[i] != '1') {
                    replace(b, b[i], '0');
                    break;
                }
            }
        }
        return stoi(a) - stoi(b);
    }
};
