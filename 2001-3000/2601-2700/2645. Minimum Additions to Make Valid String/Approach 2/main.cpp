class Solution {
public:
    int addMinimum(string word) {
        int additions = 0;
        int expected = 0;

        for (char character :
             word) {
            int current =
                character -
                'a';

            while (expected != current) {
                additions++;

                expected =
                    (expected + 1) %
                    3;
            }

            expected =
                (expected + 1) %
                3;
        }

        if (expected != 0) {
            additions +=
                3 -
                expected;
        }

        return additions;
    }
};
