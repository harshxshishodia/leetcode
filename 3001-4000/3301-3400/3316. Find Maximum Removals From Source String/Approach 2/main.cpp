class Solution {
    vector<bool> removable;
    string source;
    string pattern;

    int solve(
        int sourceIndex,
        int patternIndex
    ) {
        if (sourceIndex ==
            static_cast<int>(source.size())) {
            if (patternIndex ==
                static_cast<int>(pattern.size())) {
                return 0;
            }

            return
                -1000000000;
        }

        int answer =
            -1000000000;

        if (removable[sourceIndex]) {
            answer = max(
                answer,
                1 +
                solve(
                    sourceIndex + 1,
                    patternIndex
                )
            );
        }

        answer = max(
            answer,
            solve(
                sourceIndex + 1,
                patternIndex
            )
        );

        if (
            patternIndex <
                static_cast<int>(pattern.size()) &&
            source[sourceIndex] ==
                pattern[patternIndex]
        ) {
            answer = max(
                answer,
                solve(
                    sourceIndex + 1,
                    patternIndex + 1
                )
            );
        }

        return answer;
    }

public:
    int maxRemovals(
        string inputSource,
        string inputPattern,
        vector<int>& targetIndices
    ) {
        source =
            inputSource;

        pattern =
            inputPattern;

        removable.assign(
            source.size(),
            false
        );

        for (int index :
             targetIndices) {
            removable[index] =
                true;
        }

        return solve(
            0,
            0
        );
    }
};
