class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(
            stones.begin(),
            stones.end(),
            0
        );

        bitset<3001> possible;
        possible[0] = 1;

        for (int stone : stones) {
            possible |=
                possible << stone;
        }

        for (int sum = total / 2;
             sum >= 0;
             sum--) {
            if (possible[sum]) {
                return total - 2 * sum;
            }
        }

        return total;
    }
};
