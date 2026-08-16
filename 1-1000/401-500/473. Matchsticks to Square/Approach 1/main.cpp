class Solution {
    bool search(
        const vector<int>& matchsticks,
        int index,
        int target,
        array<int, 4>& sides
    ) {
        if (index == static_cast<int>(matchsticks.size())) {
            return sides[0] == target &&
                   sides[1] == target &&
                   sides[2] == target &&
                   sides[3] == target;
        }

        for (int side = 0; side < 4; side++) {
            if (sides[side] + matchsticks[index] > target) {
                continue;
            }

            sides[side] += matchsticks[index];

            if (search(
                    matchsticks,
                    index + 1,
                    target,
                    sides)) {
                return true;
            }

            sides[side] -= matchsticks[index];
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

        array<int, 4> sides = {0, 0, 0, 0};

        return search(
            matchsticks,
            0,
            total / 4,
            sides
        );
    }
};
