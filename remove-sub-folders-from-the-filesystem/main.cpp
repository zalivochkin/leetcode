
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        auto n = folder.size();
        ranges::sort(folder);
        vector<string> res = { folder[0] };
        string prev_folder = folder[0];
        for (auto i = 1; i < n; ++i) {
            const auto &fold = folder[i];
            if (fold.find(prev_folder + '/') != 0) {
                res.push_back(fold);
                prev_folder = fold;
            }
        }
        return res;
    }
};
