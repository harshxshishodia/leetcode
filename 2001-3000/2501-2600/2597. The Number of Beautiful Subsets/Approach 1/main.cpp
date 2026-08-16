class Solution {
public:
    int beautifulSubsets(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        int answer = 0;

        for (int mask = 1;
             mask < (1 << n);
             mask++) {
            bool valid = true;

            for (int first = 0;
                 first < n &&
                 valid;
                 first++) {
                if ((mask & (1 << first)) == 0) {
                    continue;
                }

                for (int second = first + 1;
                     second < n;
                     second++) {
                    if ((mask & (1 << second)) == 0) {
                        continue;
                    }

                    if (abs(
                            nums[first] -
                            nums[second]
                        ) == k) {
                        valid = false;
                        break;
                    }
                }
            }

            answer +=
                valid;
        }

        return answer;
    }
};
