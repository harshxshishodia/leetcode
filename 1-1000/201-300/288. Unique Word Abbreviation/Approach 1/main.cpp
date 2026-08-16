class ValidWordAbbr {
    vector<string> words;

    string getAbbreviation(const string& s) {
        if (s.size() <= 2) return s;
        return s.front() + to_string(s.size() - 2) + s.back();
    }

public:
    ValidWordAbbr(vector<string>& dictionary) : words(dictionary) {}

    bool isUnique(string word) {
        string targetAbbr = getAbbreviation(word);
        for (const string& dictWord : words) {
            if (getAbbreviation(dictWord) == targetAbbr && dictWord != word) {
                return false;
            }
        }
        return true;
    }
};
