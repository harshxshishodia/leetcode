class AuthenticationManager {
    int timeToLive;
    unordered_map<string, int> tokenExpiryMap;

public:
    AuthenticationManager(int ttl) : timeToLive(ttl) {}

    void generate(string tokenId, int currentTime) {
        tokenExpiryMap[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        auto it = tokenExpiryMap.find(tokenId);
        if (it != tokenExpiryMap.end() && it->second > currentTime) {
            it->second = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int validCount = 0;
        for (const auto& [id, expiry] : tokenExpiryMap) {
            if (expiry > currentTime) {
                validCount++;
            }
        }
        return validCount;
    }
};
