class Solution {
    bool valid(
        const vector<int>& permutation
    ) {
        for (int index = 0;
             index < static_cast<int>(permutation.size());
             index++) {
            int position =
                index +
                1;

            int value =
                permutation[index];

            if (
                value %
                    position !=
                    0 &&
                position %
                    value !=
                    0
            ) {
                return false;
            }
        }

        return true;
    }

public:
    int selfDivisiblePermutationCount(int n) {
        vector<int> permutation(n);

        iota(
            permutation.begin(),
            permutation.end(),
            1
        );

        int answer = 0;

        do {
            answer +=
                valid(
                    permutation
                );
        } while (
            next_permutation(
                permutation.begin(),
                permutation.end()
            )
        );

        return answer;
    }
};
