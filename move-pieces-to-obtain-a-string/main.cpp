
class Solution {
public:
    bool canChange(string start, string target) {
        const auto n = start.size();
        auto lft = 0;
        auto rght = 0;
        for (auto i = 0, j = 0; i < n; ++i) {
            lft += start[i] == 'L';
            lft -= target[i] == 'L';
            rght += start[i] == 'R';
            rght -= target[i] == 'R';
            if (start[i] != '_') {
                for (; j < n; ++j) {
                    if (target[j] != '_') {
                        break;
                    }
                }
                if (start[i] != target[j] || (start[i] == 'R' && i > j) || (start[i] == 'L' && i < j)) {
                    return false;
                }
                ++j;
            }
        }
        return lft == 0 && rght == 0;
    }

    bool canChangeSlow(string start, string target) {
        const auto n = start.size();
        for (auto i = 0; i < n; ++i) {
            if (start[i] != target[i]) {
                if (target[i] == 'L') {
                    if (start[i] != '_') {
                        return false;
                    }
                    for (auto j = i + 1; j < n; ++j) {
                        if (start[j] == 'L') {
                            swap(start[i], start[j]);
                            break;
                        }
                        if (start[j] == 'R') {
                            return false;
                        }
                    }
                    if (start[i] != 'L') {
                        return false;
                    }
                } else if (target[i] == '_') {
                    if (start[i] == 'L') {
                        return false;
                    }
                    for (auto j = i + 1; j < n; ++j) {
                        if (start[j] == '_') {
                            swap(start[i], start[j]);
                            break;
                        }
                        if (start[j] == 'L') {
                            return false;
                        }
                    }
                    if (start[i] != '_') {
                        return false;
                    }
                } else if (target[i] == 'R') {
                    for (auto j = i + 1; j < n; ++j) {
                        if (start[j] == '_') {
                            swap(start[i], start[j]);
                            break;
                        }
                        if (start[j] == 'L') {
                            return false;
                        }
                    }
                    if (start[i] != 'R') {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
