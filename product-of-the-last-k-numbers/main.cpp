
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        prefxs.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefxs.clear();
            prefxs.push_back(1);
            return;
        }
        prefxs.push_back(prefxs.back() * num);
    }

    int getProduct(int k) {
        const auto n = prefxs.size();
        return n <= k ? 0 : prefxs.back() / prefxs[n - k - 1];
    }

private:
    vector<int> prefxs;
};
