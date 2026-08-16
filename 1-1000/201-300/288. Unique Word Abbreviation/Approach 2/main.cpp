class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> abbreviationMap;

    string getAbbreviation(const string& s) {
        if (s.size() <= 2) return s;
        return s.front() + to_string(s.size() - 2) + s.back();
    }

public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const string& word : dictionary) {
            abbreviationMap[getAbbreviation(word)].insert(word);
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbreviation(word);
        auto it = abbreviationMap.find(abbr);
        if (it == abbreviationMap.end()) {
            return true;
        }
        return it->second.size() == 1 && it->second.count(word);
    }
};
