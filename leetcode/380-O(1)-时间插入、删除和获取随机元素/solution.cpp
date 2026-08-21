class RandomizedSet {
public:
    RandomizedSet() : generator(random_device{}()) {
    }
    
    bool insert(int val) {
        if (index.count(val)) {
            return false;
        }

        index[val] = values.size();
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = index.find(val);
        if (it == index.end()) {
            return false;
        }

        int removeIndex = it->second;
        swap(values[removeIndex], values.back());
        index[values[removeIndex]] = removeIndex;
        values.pop_back();
        index.erase(val);
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<int> distribution(0, values.size() - 1);
        return values[distribution(generator)];
    }

private:
    vector<int> values;
    unordered_map<int, int> index;
    mt19937 generator;
};
