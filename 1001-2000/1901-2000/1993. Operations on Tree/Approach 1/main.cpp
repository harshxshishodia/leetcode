class LockingTree {
    vector<int> parentNodes;
    vector<vector<int>> childrenNodes;
    vector<int> lockedByUser;

    bool hasLockedDescendant(int num) {
        for (int child : childrenNodes[num]) {
            if (lockedByUser[child] != 0 || hasLockedDescendant(child)) {
                return true;
            }
        }
        return false;
    }

    void unlockAllDescendants(int num) {
        for (int child : childrenNodes[num]) {
            lockedByUser[child] = 0;
            unlockAllDescendants(child);
        }
    }

public:
    LockingTree(vector<int>& parent)
        : parentNodes(parent), childrenNodes(parent.size()), lockedByUser(parent.size(), 0) {
        for (int i = 1; i < static_cast<int>(parent.size()); i++) {
            childrenNodes[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (lockedByUser[num] == 0) {
            lockedByUser[num] = user;
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (lockedByUser[num] == user) {
            lockedByUser[num] = 0;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (lockedByUser[num] != 0) return false;
        if (!hasLockedDescendant(num)) return false;

        int current = parentNodes[num];
        while (current != -1) {
            if (lockedByUser[current] != 0) return false;
            current = parentNodes[current];
        }

        unlockAllDescendants(num);
        lockedByUser[num] = user;
        return true;
    }
};
