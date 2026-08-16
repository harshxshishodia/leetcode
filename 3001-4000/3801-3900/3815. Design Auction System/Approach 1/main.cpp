class AuctionSystem {
    unordered_map<int, unordered_map<int, int>> itemUserBids;
    unordered_map<int, set<pair<int, int>>> itemBidsSet; // itemId -> set of (bidAmount, userId)

public:
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        if (itemUserBids[itemId].count(userId)) {
            int oldBid = itemUserBids[itemId][userId];
            itemBidsSet[itemId].erase({oldBid, userId});
        }
        itemUserBids[itemId][userId] = bidAmount;
        itemBidsSet[itemId].insert({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        int oldBid = itemUserBids[itemId][userId];
        itemBidsSet[itemId].erase({oldBid, userId});
        itemUserBids[itemId][userId] = newAmount;
        itemBidsSet[itemId].insert({newAmount, userId});
    }

    void removeBid(int userId, int itemId) {
        int oldBid = itemUserBids[itemId][userId];
        itemBidsSet[itemId].erase({oldBid, userId});
        itemUserBids[itemId].erase(userId);
    }

    int getHighestBidder(int itemId) {
        auto it = itemBidsSet.find(itemId);
        if (it == itemBidsSet.end() || it->second.empty()) {
            return -1;
        }
        return it->second.rbegin()->second;
    }
};
