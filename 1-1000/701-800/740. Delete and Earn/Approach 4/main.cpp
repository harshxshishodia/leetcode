class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> points;

        for (int number : nums) {
            points[number] += number;
        }

        int previousValue = -2;
        int previous2 = 0;
        int previous1 = 0;

        for (auto [value, earned] : points) {
            int current;

            if (value == previousValue + 1) {
                current = max(
                    previous1,
                    previous2 + earned
                );
            } else {
                current =
                    previous1 + earned;
            }

            previous2 = previous1;
            previous1 = current;
            previousValue = value;
        }

        return previous1;
    }
};
