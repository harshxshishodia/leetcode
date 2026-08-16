class Solution {
    int overlap(
        const vector<int>& first,
        const vector<int>& second,
        int firstStart,
        int secondStart,
        int length
    ) {
        int answer = 0;
        int current = 0;

        for (int offset = 0; offset < length; offset++) {
            if (first[firstStart + offset] ==
                second[secondStart + offset]) {
                current++;
                answer = max(
                    answer,
                    current
                );
            } else {
                current = 0;
            }
        }

        return answer;
    }

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int firstLength =
            static_cast<int>(nums1.size());

        int secondLength =
            static_cast<int>(nums2.size());

        int answer = 0;

        for (int firstStart = 0;
             firstStart < firstLength;
             firstStart++) {
            int length = min(
                firstLength - firstStart,
                secondLength
            );

            answer = max(
                answer,
                overlap(
                    nums1,
                    nums2,
                    firstStart,
                    0,
                    length
                )
            );
        }

        for (int secondStart = 1;
             secondStart < secondLength;
             secondStart++) {
            int length = min(
                firstLength,
                secondLength - secondStart
            );

            answer = max(
                answer,
                overlap(
                    nums1,
                    nums2,
                    0,
                    secondStart,
                    length
                )
            );
        }

        return answer;
    }
};
