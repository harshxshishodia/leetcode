class RandomizedSet {
    vector<int> elements;

public:
    RandomizedSet() {}

    bool insert(int val) {
        for (int x : elements) {
            if (x == val) return false;
        }
        elements.push_back(val);
        return true;
    }

    bool remove(int val) {
        for (auto it = elements.begin(); it != elements.end(); it++) {
            if (*it == val) {
                elements.erase(it);
                return true;
            }
        }
        return false;
    }

    int getRandom() {
        return elements[rand() % elements.size()];
    }
};
