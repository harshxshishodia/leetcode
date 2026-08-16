class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> values = arr;
        int answer = 0;

        while (values.size() > 1) {
            int index = 0;

            for (int i = 1;
                 i < static_cast<int>(values.size());
                 i++) {
                if (values[i] < values[index]) {
                    index = i;
                }
            }

            int neighbor =
                numeric_limits<int>::max();

            if (index > 0) {
                neighbor = min(
                    neighbor,
                    values[index - 1]
                );
            }

            if (index + 1 <
                static_cast<int>(values.size())) {
                neighbor = min(
                    neighbor,
                    values[index + 1]
                );
            }

            answer +=
                values[index] *
                neighbor;

            values.erase(
                values.begin() +
                index
            );
        }

        return answer;
    }
};
