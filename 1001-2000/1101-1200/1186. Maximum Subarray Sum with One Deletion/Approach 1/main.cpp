class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n =
            static_cast<int>(arr.size());

        int answer =
            numeric_limits<int>::min();

        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                for (int deleted = -1;
                     deleted <= right;
                     deleted++) {
                    if (deleted >= 0 &&
                        deleted < left) {
                        continue;
                    }

                    if (deleted == left &&
                        left == right) {
                        continue;
                    }

                    int sum = 0;

                    for (int i = left; i <= right; i++) {
                        if (i != deleted) {
                            sum += arr[i];
                        }
                    }

                    answer = max(
                        answer,
                        sum
                    );
                }
            }
        }

        return answer;
    }
};
