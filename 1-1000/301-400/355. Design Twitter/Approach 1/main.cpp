class Twitter {
    int timestampCounter;
    unordered_map<int, vector<pair<int, int>>> userTweets; // userId -> (timestamp, tweetId)
    unordered_map<int, unordered_set<int>> followingUsers; // userId -> followeeIds

public:
    Twitter() : timestampCounter(0) {}

    void postTweet(int userId, int tweetId) {
        userTweets[userId].emplace_back(++timestampCounter, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> maxHeap;

        unordered_set<int> relevantUsers = followingUsers[userId];
        relevantUsers.insert(userId);

        for (int u : relevantUsers) {
            if (userTweets.count(u) && !userTweets[u].empty()) {
                int lastIdx = static_cast<int>(userTweets[u].size()) - 1;
                maxHeap.emplace(userTweets[u][lastIdx].first, userTweets[u][lastIdx].second, u, lastIdx);
            }
        }

        vector<int> feed;
        while (!maxHeap.empty() && static_cast<int>(feed.size()) < 10) {
            auto [time, tweetId, u, idx] = maxHeap.top();
            maxHeap.pop();
            feed.push_back(tweetId);
            if (idx > 0) {
                maxHeap.emplace(userTweets[u][idx - 1].first, userTweets[u][idx - 1].second, u, idx - 1);
            }
        }
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followingUsers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followingUsers.count(followerId)) {
            followingUsers[followerId].erase(followeeId);
        }
    }
};
