class Solution {
    int search(
        int n,
        int position,
        vector<bool>& used
    ) {
        if (position > n) {
            return 1;
        }

        int answer = 0;

        for (int value = 1; value <= n; value++) {
            if (used[value]) {
                continue;
            }

            if (value % position != 0 &&
                position % value != 0) {
                continue;
            }

            used[value] = true;
            answer += search(
                n,
                position + 1,
                used
            );
            used[value] = false;
        }

        return answer;
    }

public:
    int countArrangement(int n) {
        vector<bool> used(n + 1);
        return search(n, 1, used);
    }
};
