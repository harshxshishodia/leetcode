class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> values(
            arr.begin(),
            arr.end()
        );

        int n = static_cast<int>(arr.size());
        int answer = 0;

        for (int first = 0; first < n; first++) {
            for (int second = first + 1; second < n; second++) {
                int a = arr[first];
                int b = arr[second];
                int length = 2;

                while (values.count(a + b)) {
                    int next = a + b;
                    a = b;
                    b = next;
                    length++;
                }

                answer = max(
                    answer,
                    length
                );
            }
        }

        return answer >= 3
            ? answer
            : 0;
    }
};
