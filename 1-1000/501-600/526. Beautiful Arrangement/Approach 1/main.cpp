class Solution {
    bool beautiful(const vector<int>& arrangement) {
        for (int i = 0; i < static_cast<int>(arrangement.size()); i++) {
            int position = i + 1;
            int value = arrangement[i];

            if (value % position != 0 &&
                position % value != 0) {
                return false;
            }
        }

        return true;
    }

public:
    int countArrangement(int n) {
        vector<int> values(n);

        for (int i = 0; i < n; i++) {
            values[i] = i + 1;
        }

        int answer = 0;

        do {
            if (beautiful(values)) {
                answer++;
            }
        } while (next_permutation(values.begin(), values.end()));

        return answer;
    }
};
