class Solution {
public:
    int maxNonDecreasingLength(
        vector<int>& nums1,
        vector<int>& nums2
    ) {
        int first = 1;
        int second = 1;
        int answer = 1;

        for (int index = 1;
             index < static_cast<int>(nums1.size());
             index++) {
            int nextFirst = 1;
            int nextSecond = 1;

            if (nums1[index] >=
                nums1[index - 1]) {
                nextFirst = max(
                    nextFirst,
                    first + 1
                );
            }

            if (nums1[index] >=
                nums2[index - 1]) {
                nextFirst = max(
                    nextFirst,
                    second + 1
                );
            }

            if (nums2[index] >=
                nums1[index - 1]) {
                nextSecond = max(
                    nextSecond,
                    first + 1
                );
            }

            if (nums2[index] >=
                nums2[index - 1]) {
                nextSecond = max(
                    nextSecond,
                    second + 1
                );
            }

            first =
                nextFirst;

            second =
                nextSecond;

            answer = max({
                answer,
                first,
                second
            });
        }

        return answer;
    }
};
