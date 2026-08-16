class Solution {
    int answer = 0;
    vector<bool> removable;
    vector<bool> removed;

    bool subsequence(
        const string& source,
        const string& pattern
    ) {
        int matched = 0;

        for (int index = 0;
             index < static_cast<int>(source.size()) &&
             matched <
                static_cast<int>(pattern.size());
             index++) {
            if (removed[index]) {
                continue;
            }

            if (
                source[index] ==
                pattern[matched]
            ) {
                matched++;
            }
        }

        return matched ==
            static_cast<int>(pattern.size());
    }

    void search(
        const string& source,
        const string& pattern,
        const vector<int>& targetIndices,
        int index,
        int operations
    ) {
        if (index ==
            static_cast<int>(targetIndices.size())) {
            if (subsequence(
                    source,
                    pattern)) {
                answer = max(
                    answer,
                    operations
                );
            }

            return;
        }

        search(
            source,
            pattern,
            targetIndices,
            index + 1,
            operations
        );

        int sourceIndex =
            targetIndices[index];

        removed[sourceIndex] =
            true;

        search(
            source,
            pattern,
            targetIndices,
            index + 1,
            operations + 1
        );

        removed[sourceIndex] =
            false;
    }

public:
    int maxRemovals(
        string source,
        string pattern,
        vector<int>& targetIndices
    ) {
        answer =
            0;

        removed.assign(
            source.size(),
            false
        );

        search(
            source,
            pattern,
            targetIndices,
            0,
            0
        );

        return answer;
    }
};
