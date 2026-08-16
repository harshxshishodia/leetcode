class Solution {
public:
    int maxNonDecreasingLength(
        vector<int>& nums1,
        vector<int>& nums2
    ) {
        int n =
            static_cast<int>(nums1.size());

        vector<int> useFirst(
            n,
            1
        );

        vector<int> useSecond(
            n,
            1
        );

        int answer = 1;

        for (int index = 1;
             index < n;
             index++) {
            if (nums1[index] >=
                nums1[index - 1]) {
                useFirst[index] = max(
                    useFirst[index],
                    useFirst[index - 1] + 1
                );
            }

            if (nums1[index] >=
                nums2[index - 1]) {
                useFirst[index] = max(
                    useFirst[index],
                    useSecond[index - 1] + 1
                );
            }

            if (nums2[index] >=
                nums1[index - 1]) {
                useSecond[index] = max(
                    useSecond[index],
                    useFirst[index - 1] + 1
                );
            }

            if (nums2[index] >=
                nums2[index - 1]) {
                useSecond[index] = max(
                    useSecond[index],
                    useSecond[index - 1] + 1
                );
            }

            answer = max({
                answer,
                useFirst[index],
                useSecond[index]
            });
        }

        return answer;
    }
};
