class Solution {
    static constexpr int MOD =
        1000000007;

    int n;
    int k;
    long long evenChoices;
    long long oddChoices;

    vector<
        vector<
            array<long long, 2>
        >
    > memo;

    vector<
        vector<
            array<bool, 2>
        >
    > visited;

    long long solve(
        int index,
        int count,
        int previousEven
    ) {
        if (count > k) {
            return 0;
        }

        if (index == n) {
            return count == k;
        }

        if (visited[index][count][previousEven]) {
            return memo[index][count][previousEven];
        }

        visited[index][count][previousEven] =
            true;

        long long answer = 0;

        answer +=
            oddChoices *
            solve(
                index + 1,
                count,
                0
            );

        answer %=
            MOD;

        int nextCount =
            count +
            previousEven;

        if (nextCount <= k) {
            answer +=
                evenChoices *
                solve(
                    index + 1,
                    nextCount,
                    1
                );

            answer %=
                MOD;
        }

        memo[index][count][previousEven] =
            answer;

        return answer;
    }

public:
    int countOfArrays(
        int inputN,
        int m,
        int inputK
    ) {
        n =
            inputN;

        k =
            inputK;

        evenChoices =
            m /
            2;

        oddChoices =
            m -
            evenChoices;

        memo.assign(
            n,
            vector<array<long long, 2>>(
                k + 1
            )
        );

        visited.assign(
            n,
            vector<array<bool, 2>>(
                k + 1
            )
        );

        long long answer = 0;

        if (oddChoices > 0) {
            answer +=
                oddChoices *
                solve(
                    1,
                    0,
                    0
                );
        }

        if (evenChoices > 0) {
            answer +=
                evenChoices *
                solve(
                    1,
                    0,
                    1
                );
        }

        return static_cast<int>(
            answer %
            MOD
        );
    }
};
