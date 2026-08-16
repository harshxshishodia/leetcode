class Codec {
public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        int n = static_cast<int>(s.size());
        while (i < n) {
            int hashPos = s.find('#', i);
            int len = stoi(s.substr(i, hashPos - i));
            result.push_back(s.substr(hashPos + 1, len));
            i = hashPos + 1 + len;
        }
        return result;
    }
};
