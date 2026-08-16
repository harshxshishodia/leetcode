class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int one = 0;
        int two = 0;
        int three = 0;

        for (int value : nums) {
            int nextOne =
                one +
                (value != 1);

            int nextTwo =
                min(
                    one,
                    two
                ) +
                (value != 2);

            int nextThree =
                min({
                    one,
                    two,
                    three
                }) +
                (value != 3);

            one =
                nextOne;

            two =
                nextTwo;

            three =
                nextThree;
        }

        return min({
            one,
            two,
            three
        });
    }
};
