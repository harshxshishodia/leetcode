class Solution {
public:
    long long maxScore(
        vector<int>& a,
        vector<int>& b
    ) {
        int n =
            static_cast<int>(b.size());

        long long answer =
            numeric_limits<long long>::min();

        for (int i = 0;
             i < n;
             i++) {
            for (int j = i + 1;
                 j < n;
                 j++) {
                for (int k = j + 1;
                     k < n;
                     k++) {
                    for (int l = k + 1;
                         l < n;
                         l++) {
                        long long score =
                            1LL * a[0] * b[i] +
                            1LL * a[1] * b[j] +
                            1LL * a[2] * b[k] +
                            1LL * a[3] * b[l];

                        answer = max(
                            answer,
                            score
                        );
                    }
                }
            }
        }

        return answer;
    }
};
