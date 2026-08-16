class FileSharing {
    set<int> availableUserIds;
    int nextAvailableId;
    unordered_map<int, set<int>> userOwnedChunks;

public:
    FileSharing(int m) : nextAvailableId(1) {}

    int join(vector<int> ownedChunks) {
        int assignedId;
        if (!availableUserIds.empty()) {
            assignedId = *availableUserIds.begin();
            availableUserIds.erase(availableUserIds.begin());
        } else {
            assignedId = nextAvailableId++;
        }
        userOwnedChunks[assignedId] = set<int>(ownedChunks.begin(), ownedChunks.end());
        return assignedId;
    }

    void leave(int userID) {
        if (userOwnedChunks.count(userID)) {
            userOwnedChunks.erase(userID);
            availableUserIds.insert(userID);
        }
    }

    vector<int> request(int userID, int chunkID) {
        vector<int> owners;
        for (const auto& [uId, chunks] : userOwnedChunks) {
            if (chunks.count(chunkID)) {
                owners.push_back(uId);
            }
        }
        sort(owners.begin(), owners.end());
        if (!owners.empty()) {
            userOwnedChunks[userID].insert(chunkID);
        }
        return owners;
    }
};
