class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total =
            accumulate(
                nums.begin(),
                nums.end(),
                0
            );

        vector<int> remainder1;
        vector<int> remainder2;

        for (int value : nums) {
            if (value % 3 == 1) {
                remainder1.push_back(value);
            } else if (value % 3 == 2) {
                remainder2.push_back(value);
            }
        }

        sort(
            remainder1.begin(),
            remainder1.end()
        );

        sort(
            remainder2.begin(),
            remainder2.end()
        );

        if (total % 3 == 0) {
            return total;
        }

        int removal =
            numeric_limits<int>::max();

        if (total % 3 == 1) {
            if (!remainder1.empty()) {
                removal = min(
                    removal,
                    remainder1[0]
                );
            }

            if (remainder2.size() >= 2) {
                removal = min(
                    removal,
                    remainder2[0] +
                    remainder2[1]
                );
            }
        } else {
            if (!remainder2.empty()) {
                removal = min(
                    removal,
                    remainder2[0]
                );
            }

            if (remainder1.size() >= 2) {
                removal = min(
                    removal,
                    remainder1[0] +
                    remainder1[1]
                );
            }
        }

        return removal ==
               numeric_limits<int>::max()
            ? 0
            : total - removal;
    }
};
