class Solution {
    unordered_map<string, string> shortToLongMap;
    unordered_map<string, string> longToShortMap;
    const string BASE_URL = "http://tinyurl.com/";
    int urlCounter = 0;

public:
    string encode(string longUrl) {
        if (longToShortMap.count(longUrl)) {
            return longToShortMap[longUrl];
        }
        string shortUrl = BASE_URL + to_string(++urlCounter);
        shortToLongMap[shortUrl] = longUrl;
        longToShortMap[longUrl] = shortUrl;
        return shortUrl;
    }

    string decode(string shortUrl) {
        return shortToLongMap[shortUrl];
    }
};
