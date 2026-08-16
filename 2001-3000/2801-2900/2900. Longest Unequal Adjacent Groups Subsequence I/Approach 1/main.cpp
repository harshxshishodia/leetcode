class Solution {
    vector<string> best;

    void search(
        const vector<string>& words,
        const vector<int>& groups,
        int index,
        int previousGroup,
        vector<string>& current
    ) {
        if (index == static_cast<int>(words.size())) {
            if (current.size() > best.size()) {
                best = current;
            }

            return;
        }

        search(words, groups, index + 1, previousGroup, current);

        if (previousGroup == -1 || groups[index] != previousGroup) {
            current.push_back(words[index]);
            search(words, groups, index + 1, groups[index], current);
            current.pop_back();
        }
    }

public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> current;
        search(words, groups, 0, -1, current);
        return best;
    }
};
