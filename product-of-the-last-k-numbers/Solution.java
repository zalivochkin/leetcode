
import java.util.*;

class ProductOfNumbers {
    private final List<Integer> prefxs = new ArrayList<>();

    public ProductOfNumbers() {
        prefxs.add(1);
    }

    public void add(int num) {
        if (num == 0) {
            prefxs.clear();
            prefxs.add(1);
            return;
        }
        prefxs.add(prefxs.get(prefxs.size() - 1) * num);
    }

    public int getProduct(int k) {
        final var n = prefxs.size();
        return n <= k ? 0 : prefxs.get(n - 1) / prefxs.get(n - k - 1);
    }
}
