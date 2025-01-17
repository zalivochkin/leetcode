
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int derived_xor = 0;
        for (auto num : derived) {
            derived_xor ^= num;
        }
        return derived_xor == 0;
    }
};
