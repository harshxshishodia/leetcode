class Solution {
    int suffixSum(
        const string& s,
        int index
    ) {
        int answer = 0;

        for (int i = index;
             i < static_cast<int>(s.size());
             i++) {
            answer += static_cast<unsigned char>(s[i]);
        }

        return answer;
    }

    int solve(
        const string& first,
        const string& second,
        int i,
        int j
    ) {
        if (i == static_cast<int>(first.size())) {
            return suffixSum(
                second,
                j
            );
        }

        if (j == static_cast<int>(second.size())) {
            return suffixSum(
                first,
                i
            );
        }

        if (first[i] == second[j]) {
            return solve(
                first,
                second,
                i + 1,
                j + 1
            );
        }

        return min(
            static_cast<unsigned char>(first[i]) +
            solve(
                first,
                second,
                i + 1,
                j
            ),
            static_cast<unsigned char>(second[j]) +
            solve(
                first,
                second,
                i,
                j + 1
            )
        );
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        return solve(
            s1,
            s2,
            0,
            0
        );
    }
};
