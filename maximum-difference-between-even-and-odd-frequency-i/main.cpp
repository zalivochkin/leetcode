
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        for(auto ch : s) {
            freq[ch - 'a'] += 1;
        }
        int maxOdd = 0;
        int minEven = numeric_limits<int>::max();
        for(auto x : freq) {
            if(x == 0) {
                continue;
            }
            if(x % 2 == 1){
                maxOdd = std::max(maxOdd, x);
            }else {
                minEven = std::min(minEven, x);
            }
        }
        return maxOdd - minEven;
    }
};
