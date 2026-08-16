class Solution {
public:
    int longestCommonSubsequence(
        string text1,
        string text2
    ) {
        if (text1.size() < text2.size()) {
            swap(
                text1,
                text2
            );
        }

        int firstLength =
            static_cast<int>(text1.size());

        int secondLength =
            static_cast<int>(text2.size());

        vector<int> previous(
            secondLength + 1
        );

        for (int first = 1; first <= firstLength; first++) {
            vector<int> current(
                secondLength + 1
            );

            for (int second = 1; second <= secondLength; second++) {
                if (text1[first - 1] == text2[second - 1]) {
                    current[second] =
                        1 +
                        previous[second - 1];
                } else {
                    current[second] = max(
                        previous[second],
                        current[second - 1]
                    );
                }
            }

            previous = current;
        }

        return previous[secondLength];
    }
};
