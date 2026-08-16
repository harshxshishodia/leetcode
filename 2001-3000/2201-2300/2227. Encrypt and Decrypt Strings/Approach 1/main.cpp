class Encrypter {
    unordered_map<char, string> characterEncryptionMap;
    unordered_map<string, int> encryptedDictionaryCounts;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for (int i = 0; i < static_cast<int>(keys.size()); i++) {
            characterEncryptionMap[keys[i]] = values[i];
        }
        for (const string& word : dictionary) {
            string enc = encrypt(word);
            if (!enc.empty()) {
                encryptedDictionaryCounts[enc]++;
            }
        }
    }

    string encrypt(string word1) {
        string encryptedString = "";
        for (char c : word1) {
            if (!characterEncryptionMap.count(c)) {
                return "";
            }
            encryptedString += characterEncryptionMap[c];
        }
        return encryptedString;
    }

    int decrypt(string word2) {
        auto it = encryptedDictionaryCounts.find(word2);
        return it != encryptedDictionaryCounts.end() ? it->second : 0;
    }
};
