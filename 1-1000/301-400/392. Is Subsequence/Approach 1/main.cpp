class Solution {
    bool search(const string& s, const string& t, int index, string& current) {
        if (index == static_cast<int>(t.size())) {
            return current == s;
        }

        if (search(s, t, index + 1, current)) {
            return true;
        }

        current.push_back(t[index]);

        if (search(s, t, index + 1, current)) {
            return true;
        }

        current.pop_back();
        return false;
    }

public:
    bool isSubsequence(string s, string t) {
        string current;
        return search(s, t, 0, current);
    }
};
