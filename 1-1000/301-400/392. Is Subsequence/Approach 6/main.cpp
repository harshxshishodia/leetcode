class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> positions(256);

        for (int i = 0; i < static_cast<int>(t.size()); i++) {
            positions[static_cast<unsigned char>(t[i])].push_back(i);
        }

        int previous = -1;

        for (char character : s) {
            const vector<int>& indices = positions[static_cast<unsigned char>(character)];
            auto position = upper_bound(indices.begin(), indices.end(), previous);

            if (position == indices.end()) {
                return false;
            }

            previous = *position;
        }

        return true;
    }
};
