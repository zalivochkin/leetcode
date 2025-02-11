
class Solution {
public:
    string removeOccurrences(string s, string part) {
        const auto m = part.size();
        auto pos = s.find(part);
        while (pos != -1) {
            s = s.erase(pos, m);
            pos = s.find(part);
        }
        return s;
    }
};
