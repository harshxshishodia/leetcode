class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;
        bool hasZero = false;

        for (int value : nums) {
            if (value > 0) {
                positive.push_back(value);
            } else if (value < 0) {
                negative.push_back(value);
            } else {
                hasZero = true;
            }
        }

        sort(
            negative.begin(),
            negative.end()
        );

        long long product = 1;
        int selected = 0;

        for (int value : positive) {
            product *=
                value;

            selected++;
        }

        int usable =
            static_cast<int>(negative.size());

        if (usable % 2 == 1) {
            usable--;
        }

        for (int index = 0;
             index < usable;
             index++) {
            product *=
                negative[index];

            selected++;
        }

        if (selected > 0) {
            return product;
        }

        if (hasZero) {
            return 0;
        }

        return *max_element(
            nums.begin(),
            nums.end()
        );
    }
};
