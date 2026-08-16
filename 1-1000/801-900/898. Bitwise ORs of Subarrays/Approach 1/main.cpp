class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> values;

        for (int left = 0;
             left < static_cast<int>(arr.size());
             left++) {
            int current = 0;

            for (int right = left;
                 right < static_cast<int>(arr.size());
                 right++) {
                current |= arr[right];
                values.insert(current);
            }
        }

        return static_cast<int>(
            values.size()
        );
    }
};
