class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n =
            static_cast<int>(arr.size());

        vector<int> keep(n);
        vector<int> erase(n);

        keep[0] = arr[0];
        erase[0] =
            numeric_limits<int>::min() / 4;

        int answer = arr[0];

        for (int i = 1; i < n; i++) {
            erase[i] = max(
                erase[i - 1] + arr[i],
                keep[i - 1]
            );

            keep[i] = max(
                arr[i],
                keep[i - 1] + arr[i]
            );

            answer = max({
                answer,
                keep[i],
                erase[i]
            });
        }

        return answer;
    }
};
