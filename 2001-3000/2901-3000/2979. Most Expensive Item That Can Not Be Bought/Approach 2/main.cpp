class Solution {
public:
    int mostExpensiveItem(
        int primeOne,
        int primeTwo
    ) {
        int limit =
            primeOne *
            primeTwo;

        vector<bool> reachable(
            limit + 1
        );

        reachable[0] = true;

        int answer = 0;

        for (int price = 1;
             price <= limit;
             price++) {
            if (
                price >= primeOne &&
                reachable[
                    price -
                    primeOne
                ]
            ) {
                reachable[price] =
                    true;
            }

            if (
                price >= primeTwo &&
                reachable[
                    price -
                    primeTwo
                ]
            ) {
                reachable[price] =
                    true;
            }

            if (!reachable[price]) {
                answer =
                    price;
            }
        }

        return answer;
    }
};
