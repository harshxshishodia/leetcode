class Solution {
    int n;
    vector<bool> used;

    int search(int position) {
        if (position > n) {
            return 1;
        }

        int answer = 0;

        for (int value = 1;
             value <= n;
             value++) {
            if (used[value]) {
                continue;
            }

            if (
                value %
                    position !=
                    0 &&
                position %
                    value !=
                    0
            ) {
                continue;
            }

            used[value] =
                true;

            answer +=
                search(
                    position +
                    1
                );

            used[value] =
                false;
        }

        return answer;
    }

public:
    int selfDivisiblePermutationCount(int inputN) {
        n =
            inputN;

        used.assign(
            n + 1,
            false
        );

        return search(1);
    }
};
