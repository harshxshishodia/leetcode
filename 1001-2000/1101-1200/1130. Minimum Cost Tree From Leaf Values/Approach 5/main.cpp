class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int answer = 0;
        vector<int> stack = {
            numeric_limits<int>::max()
        };

        for (int value : arr) {
            while (stack.back() <= value) {
                int middle =
                    stack.back();

                stack.pop_back();

                answer +=
                    middle *
                    min(
                        stack.back(),
                        value
                    );
            }

            stack.push_back(value);
        }

        while (stack.size() > 2) {
            int middle =
                stack.back();

            stack.pop_back();

            answer +=
                middle *
                stack.back();
        }

        return answer;
    }
};
