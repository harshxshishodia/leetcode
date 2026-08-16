class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> answer;
        unordered_set<int> previous;

        for (int value : arr) {
            unordered_set<int> current;

            current.insert(value);

            for (int result : previous) {
                current.insert(
                    result | value
                );
            }

            for (int result : current) {
                answer.insert(result);
            }

            previous = move(current);
        }

        return static_cast<int>(
            answer.size()
        );
    }
};
