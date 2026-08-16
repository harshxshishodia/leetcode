class Codec {
public:
    string encode(vector<string>& strs) {
        string encodedString = "";
        for (const string& s : strs) {
            string escaped = "";
            for (char c : s) {
                if (c == '/') {
                    escaped += "//";
                } else if (c == ':') {
                    escaped += "/:";
                } else {
                    escaped += c;
                }
            }
            encodedString += escaped + ":;";
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        string currentWord = "";
        int i = 0;
        int n = static_cast<int>(s.size());
        while (i < n) {
            if (i + 1 < n && s[i] == ':' && s[i + 1] == ';') {
                decodedStrings.push_back(currentWord);
                currentWord = "";
                i += 2;
            } else if (i + 1 < n && s[i] == '/' && s[i + 1] == '/') {
                currentWord += '/';
                i += 2;
            } else if (i + 1 < n && s[i] == '/' && s[i + 1] == ':') {
                currentWord += ':';
                i += 2;
            } else {
                currentWord += s[i++];
            }
        }
        return decodedStrings;
    }
};
