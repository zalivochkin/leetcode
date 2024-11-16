
class Solution {
public:
    char findKthBit(int n, int k) {
        string S = "0";
        string RS;
        size_t mid;
        for (auto i = n - 1; i > 0 && S.size() <= k; --i) {
            RS = S;
            mid = S.size() / 2;
            RS[mid] = RS[mid] == '0' ? '1' : '0';
            S.push_back('1');
            S += RS;
        }
        return S[k - 1];
    }
};
