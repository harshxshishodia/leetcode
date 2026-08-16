class Solution {
public:
    int minimumPartition(
        string s,
        int k
    ) {
        int segments = 1;
        long long current = 0;

        for (char digit :
             s) {
            int value =
                digit - '0';

            if (value > k) {
                return -1;
            }

            long long next =
                current *
                10 +
                value;

            if (next > k) {
                segments++;
                current =
                    value;
            } else {
                current =
                    next;
            }
        }

        return segments;
    }
};
