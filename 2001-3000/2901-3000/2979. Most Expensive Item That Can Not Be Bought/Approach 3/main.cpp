class Solution {
public:
    int mostExpensiveItem(
        int primeOne,
        int primeTwo
    ) {
        vector<int> minimum(
            primeOne,
            numeric_limits<int>::max()
        );

        for (int count = 0;
             count < primeOne;
             count++) {
            int value =
                count *
                primeTwo;

            int remainder =
                value %
                primeOne;

            minimum[remainder] = min(
                minimum[remainder],
                value
            );
        }

        int answer = 0;

        for (int remainder = 0;
             remainder < primeOne;
             remainder++) {
            if (minimum[remainder] == 0) {
                continue;
            }

            answer = max(
                answer,
                minimum[remainder] -
                primeOne
            );
        }

        return answer;
    }
};
