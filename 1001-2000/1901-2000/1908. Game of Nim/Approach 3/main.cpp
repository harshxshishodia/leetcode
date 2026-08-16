class Solution {
public:
    bool nimGame(vector<int>& piles) {
        int xorSum = 0;

        for (int pile : piles) {
            xorSum ^=
                pile;
        }

        return xorSum != 0;
    }
};
