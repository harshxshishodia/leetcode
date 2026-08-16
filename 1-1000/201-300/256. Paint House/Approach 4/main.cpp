class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }

        int red = costs[0][0];
        int blue = costs[0][1];
        int green = costs[0][2];

        for (int house = 1; house < static_cast<int>(costs.size()); house++) {
            int nextRed = costs[house][0] + min(blue, green);
            int nextBlue = costs[house][1] + min(red, green);
            int nextGreen = costs[house][2] + min(red, blue);

            red = nextRed;
            blue = nextBlue;
            green = nextGreen;
        }

        return min({red, blue, green});
    }
};
