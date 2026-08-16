class Solution {
    bool validMove(
        const vector<int>& pattern,
        int next
    ) {
        if (pattern.empty()) {
            return true;
        }

        int previous = pattern.back();
        int middle = 0;

        if ((previous == 1 && next == 3) ||
            (previous == 3 && next == 1)) {
            middle = 2;
        } else if ((previous == 1 && next == 7) ||
                   (previous == 7 && next == 1)) {
            middle = 4;
        } else if ((previous == 3 && next == 9) ||
                   (previous == 9 && next == 3)) {
            middle = 6;
        } else if ((previous == 7 && next == 9) ||
                   (previous == 9 && next == 7)) {
            middle = 8;
        } else if ((previous == 1 && next == 9) ||
                   (previous == 9 && next == 1) ||
                   (previous == 3 && next == 7) ||
                   (previous == 7 && next == 3) ||
                   (previous == 4 && next == 6) ||
                   (previous == 6 && next == 4) ||
                   (previous == 2 && next == 8) ||
                   (previous == 8 && next == 2)) {
            middle = 5;
        }

        if (middle == 0) {
            return true;
        }

        return find(
            pattern.begin(),
            pattern.end(),
            middle
        ) != pattern.end();
    }

    int search(
        int targetLength,
        vector<int>& pattern,
        vector<bool>& used
    ) {
        if (static_cast<int>(pattern.size()) == targetLength) {
            return 1;
        }

        int answer = 0;

        for (int next = 1; next <= 9; next++) {
            if (used[next] ||
                !validMove(pattern, next)) {
                continue;
            }

            used[next] = true;
            pattern.push_back(next);

            answer += search(
                targetLength,
                pattern,
                used
            );

            pattern.pop_back();
            used[next] = false;
        }

        return answer;
    }

public:
    int numberOfPatterns(int m, int n) {
        int answer = 0;

        for (int length = m; length <= n; length++) {
            vector<int> pattern;
            vector<bool> used(10);
            answer += search(length, pattern, used);
        }

        return answer;
    }
};
