class Solution {
public:
    int minSumOfLengths(
        vector<int>& arr,
        int target
    ) {
        int n =
            static_cast<int>(arr.size());

        vector<pair<int, int>> segments;

        for (int left = 0; left < n; left++) {
            int sum = 0;

            for (int right = left; right < n; right++) {
                sum += arr[right];

                if (sum == target) {
                    segments.push_back({
                        left,
                        right
                    });
                }
            }
        }

        int answer =
            numeric_limits<int>::max();

        for (int first = 0;
             first < static_cast<int>(segments.size());
             first++) {
            for (int second = first + 1;
                 second < static_cast<int>(segments.size());
                 second++) {
                auto [left1, right1] =
                    segments[first];

                auto [left2, right2] =
                    segments[second];

                if (right1 < left2 ||
                    right2 < left1) {
                    answer = min(
                        answer,
                        right1 - left1 + 1 +
                        right2 - left2 + 1
                    );
                }
            }
        }

        return answer ==
               numeric_limits<int>::max()
            ? -1
            : answer;
    }
};
