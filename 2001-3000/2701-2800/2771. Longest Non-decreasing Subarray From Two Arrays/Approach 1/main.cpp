class Solution {
public:
    int maxNonDecreasingLength(
        vector<int>& nums1,
        vector<int>& nums2
    ) {
        int n =
            static_cast<int>(nums1.size());

        int answer = 1;

        for (int mask = 0;
             mask < (1 << n);
             mask++) {
            vector<int> chosen(n);

            for (int index = 0;
                 index < n;
                 index++) {
                chosen[index] =
                    (mask & (1 << index))
                        ? nums2[index]
                        : nums1[index];
            }

            int length = 1;

            for (int index = 1;
                 index < n;
                 index++) {
                if (chosen[index] >=
                    chosen[index - 1]) {
                    length++;
                } else {
                    length = 1;
                }

                answer = max(
                    answer,
                    length
                );
            }
        }

        return answer;
    }
};
