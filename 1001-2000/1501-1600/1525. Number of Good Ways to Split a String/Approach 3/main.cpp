class Solution {
public:
    int numSplits(string s) {
        array<int, 26> leftCount = {};
        array<int, 26> rightCount = {};

        int leftDistinct = 0;
        int rightDistinct = 0;

        for (char character : s) {
            int index =
                character - 'a';

            if (rightCount[index] == 0) {
                rightDistinct++;
            }

            rightCount[index]++;
        }

        int answer = 0;

        for (int i = 0;
             i + 1 < static_cast<int>(s.size());
             i++) {
            int index =
                s[i] - 'a';

            if (leftCount[index] == 0) {
                leftDistinct++;
            }

            leftCount[index]++;

            rightCount[index]--;

            if (rightCount[index] == 0) {
                rightDistinct--;
            }

            if (leftDistinct ==
                rightDistinct) {
                answer++;
            }
        }

        return answer;
    }
};
