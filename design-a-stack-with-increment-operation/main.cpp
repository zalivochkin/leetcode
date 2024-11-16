
class CustomStack {
public:
    CustomStack(int maxSize) {
        data.resize(maxSize);
        cur_size = 0;
    }

    void push(int x) {
        if (cur_size < data.size()) {
            data[cur_size] = x;
            ++cur_size;
        }
    }

    int pop() {
        if (cur_size == 0) {
            return -1;
        }
        --cur_size;
        return data[cur_size];
    }

    void increment(int k, int val) {
        auto min_k = min(k, cur_size);
        for (auto i = 0; i < min_k; ++i) {
            data[i] += val;
        }
    }

private:
    vector<int> data;
    int cur_size;
};
