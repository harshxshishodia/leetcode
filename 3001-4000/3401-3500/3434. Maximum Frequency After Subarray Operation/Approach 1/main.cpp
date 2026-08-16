class Solution {
public:
    int maxFrequency(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        int answer = 0;

        for (int left = 0;
             left < n;
             left++) {
            for (int right = left;
                 right < n;
                 right++) {
                for (int value = 1;
                     value <= 50;
                     value++) {
                    int x =
                        k -
                        value;

                    int frequency = 0;

                    for (int index = 0;
                         index < n;
                         index++) {
                        int current =
                            nums[index];

                        if (
                            index >= left &&
                            index <= right
                        ) {
                            current +=
                                x;
                        }

                        frequency +=
                            current ==
                            k;
                    }

                    answer = max(
                        answer,
                        frequency
                    );
                }
            }
        }

        return answer;
    }
};
