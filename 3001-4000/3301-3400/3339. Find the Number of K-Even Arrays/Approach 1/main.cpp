class Solution {
    static constexpr int MOD =
        1000000007;

    int n;
    int m;
    int k;
    long long answer;

    void search(
        int index,
        int previousEven,
        int count
    ) {
        if (count > k) {
            return;
        }

        if (index == n) {
            if (count == k) {
                answer++;
                answer %=
                    MOD;
            }

            return;
        }

        for (int value = 1;
             value <= m;
             value++) {
            int currentEven =
                value % 2 ==
                0;

            int nextCount =
                count +
                (
                    index > 0 &&
                    previousEven &&
                    currentEven
                );

            search(
                index + 1,
                currentEven,
                nextCount
            );
        }
    }

public:
    int countOfArrays(
        int inputN,
        int inputM,
        int inputK
    ) {
        n =
            inputN;

        m =
            inputM;

        k =
            inputK;

        answer =
            0;

        search(
            0,
            0,
            0
        );

        return static_cast<int>(
            answer
        );
    }
};
