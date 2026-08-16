class SnapshotArray {
    vector<vector<pair<int, int>>> changeHistory;
    int currentSnapId;

public:
    SnapshotArray(int length) : changeHistory(length), currentSnapId(0) {
        for (int i = 0; i < length; i++) {
            changeHistory[i].emplace_back(0, 0);
        }
    }

    void set(int index, int val) {
        if (changeHistory[index].back().first == currentSnapId) {
            changeHistory[index].back().second = val;
        } else {
            changeHistory[index].emplace_back(currentSnapId, val);
        }
    }

    int snap() {
        return currentSnapId++;
    }

    int get(int index, int snap_id) {
        const auto& history = changeHistory[index];
        auto it = upper_bound(history.begin(), history.end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};
