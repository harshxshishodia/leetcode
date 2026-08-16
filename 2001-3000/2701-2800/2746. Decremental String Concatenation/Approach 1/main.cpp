class Solution {
    int joinCost(
        const string& first,
        const string& second
    ) {
        return
            static_cast<int>(
                first.size() +
                second.size()
            ) -
            (
                first.back() ==
                second.front()
            );
    }

    int solve(
        const vector<string>& words,
        int index,
        string current
    ) {
        if (index ==
            static_cast<int>(words.size())) {
            return static_cast<int>(
                current.size()
            );
        }

        string append =
            current +
            words[index];

        if (current.back() ==
            words[index].front()) {
            append.erase(
                current.size() - 1,
                1
            );
        }

        string prepend =
            words[index] +
            current;

        if (words[index].back() ==
            current.front()) {
            prepend.erase(
                words[index].size() - 1,
                1
            );
        }

        return min(
            solve(
                words,
                index + 1,
                append
            ),
            solve(
                words,
                index + 1,
                prepend
            )
        );
    }

public:
    int minimizeConcatenatedLength(
        vector<string>& words
    ) {
        return solve(
            words,
            1,
            words[0]
        );
    }
};
