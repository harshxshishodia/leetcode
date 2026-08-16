class Leaderboard {
    unordered_map<int, int> playerScores;
    multiset<int> scoreMultiset;

public:
    Leaderboard() {}

    void addScore(int playerId, int score) {
        if (playerScores.count(playerId)) {
            int oldScore = playerScores[playerId];
            scoreMultiset.erase(scoreMultiset.find(oldScore));
            playerScores[playerId] += score;
        } else {
            playerScores[playerId] = score;
        }
        scoreMultiset.insert(playerScores[playerId]);
    }

    int top(int K) {
        int sum = 0;
        auto it = scoreMultiset.rbegin();
        for (int i = 0; i < K && it != scoreMultiset.rend(); i++, it++) {
            sum += *it;
        }
        return sum;
    }

    void reset(int playerId) {
        if (playerScores.count(playerId)) {
            int oldScore = playerScores[playerId];
            scoreMultiset.erase(scoreMultiset.find(oldScore));
            playerScores.erase(playerId);
        }
    }
};
