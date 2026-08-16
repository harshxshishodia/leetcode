class Solution {
    vector<bool> removable;
    string source;
    string pattern;
    vector<vector<int>> memo;
    vector<vector<bool>> visited;

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

        if (visited[sourceIndex][patternIndex]) {
            return memo[sourceIndex][patternIndex];
        }

        visited[sourceIndex][patternIndex] =
            true;

        int answer =
            solve(
                sourceIndex + 1,
                patternIndex
            );

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

        memo[sourceIndex][patternIndex] =
            answer;

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

        int n =
            static_cast<int>(source.size());

        int m =
            static_cast<int>(pattern.size());

        memo.assign(
            n,
            vector<int>(
                m + 1
            )
        );

        visited.assign(
            n,
            vector<bool>(
                m + 1
            )
        );

        return solve(
            0,
            0
        );
    }
};
