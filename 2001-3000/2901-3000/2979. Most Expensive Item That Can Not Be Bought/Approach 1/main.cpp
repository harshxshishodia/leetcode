class Solution {
    bool canBuy(
        int price,
        int primeOne,
        int primeTwo
    ) {
        for (int first = 0;
             first *
             primeOne <=
             price;
             first++) {
            int remaining =
                price -
                first *
                primeOne;

            if (remaining %
                primeTwo ==
                0) {
                return true;
            }
        }

        return false;
    }

public:
    int mostExpensiveItem(
        int primeOne,
        int primeTwo
    ) {
        int limit =
            primeOne *
            primeTwo;

        int answer = 0;

        for (int price = 1;
             price < limit;
             price++) {
            if (!canBuy(
                    price,
                    primeOne,
                    primeTwo)) {
                answer =
                    price;
            }
        }

        return answer;
    }
};
