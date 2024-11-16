
class AllOne {
public:
    AllOne() {

    }

    void inc(string key) {
        auto prev_count = count[key];
        count[key] += 1;
        se.erase({prev_count, key});
        se.insert({prev_count + 1, key});
    }

    void dec(string key) {
        auto prev_count = count[key];
        count[key] -= 1;
        se.erase({prev_count, key});
        if (count[key] > 0) {
            se.insert({prev_count - 1, key});
        } else {
            count.erase(key);
        }
    }

    string getMaxKey() {
        return se.empty() ? "" : se.rbegin()->second;
    }

    string getMinKey() {
        return se.empty() ? "" : se.begin()->second;
    }

private:
    unordered_map<string, int> count;
    set<pair<int, string>> se;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
