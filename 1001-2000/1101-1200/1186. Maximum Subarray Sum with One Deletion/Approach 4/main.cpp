class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int keep =
            arr[0];

        int erase =
            numeric_limits<int>::min() / 4;

        int answer =
            arr[0];

        for (int i = 1;
             i < static_cast<int>(arr.size());
             i++) {
            erase = max(
                erase + arr[i],
                keep
            );

            keep = max(
                arr[i],
                keep + arr[i]
            );

            answer = max({
                answer,
                keep,
                erase
            });
        }

        return answer;
    }
};
