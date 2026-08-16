class Solution {
    unordered_map<long long, int> memo;
    unordered_map<int, int> index;
    vector<int>* values;

    int solve(
        int first,
        int second
    ) {
        long long key =
            (
                static_cast<long long>(first) << 32
            ) |
            static_cast<unsigned int>(second);

        auto found =
            memo.find(key);

        if (found != memo.end()) {
            return found->second;
        }

        int nextValue =
            (*values)[first] +
            (*values)[second];

        auto position =
            index.find(nextValue);

        int answer = 2;

        if (position != index.end()) {
            answer =
                1 +
                solve(
                    second,
                    position->second
                );
        }

        memo[key] = answer;
        return memo[key];
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        values = &arr;
        memo.clear();
        index.clear();

        for (int i = 0; i < static_cast<int>(arr.size()); i++) {
            index[arr[i]] = i;
        }

        int answer = 0;

        for (int first = 0;
             first < static_cast<int>(arr.size());
             first++) {
            for (int second = first + 1;
                 second < static_cast<int>(arr.size());
                 second++) {
                answer = max(
                    answer,
                    solve(
                        first,
                        second
                    )
                );
            }
        }

        return answer >= 3
            ? answer
            : 0;
    }
};
