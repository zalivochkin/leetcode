
import java.util.*;

class NumberContainers {

    public NumberContainers() {

    }

    public void change(int index, int number) {
        if (numbers.containsKey(index)) {
            int oldNumber = numbers.get(index);
            indexes.get(oldNumber).remove(index);
        }
        numbers.put(index, number);
        indexes.computeIfAbsent(number, k -> new TreeSet<>()).add(index);
    }

    public int find(int number) {
        var idxs = indexes.get(number);
        if (idxs != null && !idxs.isEmpty()) {
            return idxs.first();
        }
        return -1;
    }

    private Map<Integer, Integer> numbers = new HashMap<>();
    private Map<Integer, TreeSet<Integer>> indexes = new HashMap<>();
}
