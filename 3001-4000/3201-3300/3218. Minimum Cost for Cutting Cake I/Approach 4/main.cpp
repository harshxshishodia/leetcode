class Solution {
public:
    int minimumCost(
        int m,
        int n,
        vector<int>& horizontalCut,
        vector<int>& verticalCut
    ) {
        sort(
            horizontalCut.begin(),
            horizontalCut.end(),
            greater<int>()
        );

        sort(
            verticalCut.begin(),
            verticalCut.end(),
            greater<int>()
        );

        int horizontalPieces = 1;
        int verticalPieces = 1;

        int horizontalIndex = 0;
        int verticalIndex = 0;

        long long answer = 0;

        while (
            horizontalIndex <
                static_cast<int>(horizontalCut.size()) ||
            verticalIndex <
                static_cast<int>(verticalCut.size())
        ) {
            if (
                verticalIndex ==
                    static_cast<int>(verticalCut.size()) ||
                (
                    horizontalIndex <
                        static_cast<int>(horizontalCut.size()) &&
                    horizontalCut[horizontalIndex] >=
                        verticalCut[verticalIndex]
                )
            ) {
                answer +=
                    1LL *
                    horizontalCut[horizontalIndex] *
                    verticalPieces;

                horizontalPieces++;
                horizontalIndex++;
            } else {
                answer +=
                    1LL *
                    verticalCut[verticalIndex] *
                    horizontalPieces;

                verticalPieces++;
                verticalIndex++;
            }
        }

        return static_cast<int>(
            answer
        );
    }
};
