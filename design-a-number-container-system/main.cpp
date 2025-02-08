
class NumberContainers {
public:
    NumberContainers() {

    }

    void change(int index, int number) {
        if (numbers.contains(index)) {
            int prev_number = numbers[index];
            indexes[prev_number].erase(index);
            if (indexes[prev_number].empty()) {
                indexes.erase(prev_number);
            }
        }
        numbers[index] = number;
        indexes[number].insert(index);
    }

    int find(int number) {
        if (indexes.contains(number)) {
            return *indexes[number].begin();
        }
        return -1;
    }

private:
    unordered_map<int, int> numbers;
    unordered_map<int, set<int>> indexes;
};
