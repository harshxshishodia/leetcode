class Solution {
    bool search(
        const vector<int>& matchsticks,
        int index,
        int target,
        array<int, 4>& sides
    ) {
        if (index == static_cast<int>(matchsticks.size())) {
            return true;
        }

        int value = matchsticks[index];

        for (int side = 0; side < 4; side++) {
            if (sides[side] + value > target) {
                continue;
            }

            bool duplicate = false;

            for (int previous = 0; previous < side; previous++) {
                if (sides[previous] == sides[side]) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                continue;
            }

            sides[side] += value;

            if (search(
                    matchsticks,
                    index + 1,
                    target,
                    sides)) {
                return true;
            }

            sides[side] -= value;
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(
            matchsticks.begin(),
            matchsticks.end(),
            0
        );

        if (total % 4 != 0) {
            return false;
        }

        int target = total / 4;

        sort(
            matchsticks.begin(),
            matchsticks.end(),
            greater<int>()
        );

        if (!matchsticks.empty() &&
            matchsticks[0] > target) {
            return false;
        }

        array<int, 4> sides = {0, 0, 0, 0};

        return search(
            matchsticks,
            0,
            target,
            sides
        );
    }
};
