class Leaderboard {
    unordered_map<int, int> playerScores;

public:
    Leaderboard() {}

    void addScore(int playerId, int score) {
        playerScores[playerId] += score;
    }

    int top(int K) {
        vector<int> allScores;
        for (const auto& [id, score] : playerScores) {
            allScores.push_back(score);
        }
        sort(allScores.begin(), allScores.end(), greater<int>());
        int totalTopSum = 0;
        for (int i = 0; i < min(K, static_cast<int>(allScores.size())); i++) {
            totalTopSum += allScores[i];
        }
        return totalTopSum;
    }

    void reset(int playerId) {
        playerScores.erase(playerId);
    }
};
