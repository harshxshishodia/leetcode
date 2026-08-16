class SORTracker {
    struct LocationItem {
        int score;
        string name;
        bool operator<(const LocationItem& other) const {
            if (score != other.score) return score > other.score;
            return name < other.name;
        }
    };

    set<LocationItem> fullLocationsSet;
    set<LocationItem>::iterator currentRankIterator;
    bool hasInitializedIterator;

public:
    SORTracker() : hasInitializedIterator(false) {}

    void add(string name, int score) {
        LocationItem newItem = {score, name};
        fullLocationsSet.insert(newItem);
        if (hasInitializedIterator && newItem < *currentRankIterator) {
            currentRankIterator--;
        }
    }

    string get() {
        if (!hasInitializedIterator) {
            currentRankIterator = fullLocationsSet.begin();
            hasInitializedIterator = true;
        } else {
            currentRankIterator++;
        }
        return currentRankIterator->name;
    }
};
