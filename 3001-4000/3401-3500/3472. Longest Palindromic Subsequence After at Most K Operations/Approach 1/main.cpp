class Solution {
    int distance(
        char first,
        char second
    ) {
        int difference =
            abs(
                first -
                second
            );

        return min(
            difference,
            26 -
            difference
        );
    }

    bool possible(
        const string& chosen,
        int k
    ) {
        int left = 0;
        int right =
            static_cast<int>(chosen.size()) -
            1;

        int cost = 0;

        while (left < right) {
            cost +=
                distance(
                    chosen[left],
                    chosen[right]
                );

            left++;
            right--;
        }

        return cost <= k;
    }

    int answer = 0;

    void search(
        const string& s,
        int k,
        int index,
        string& chosen
    ) {
        if (index ==
            static_cast<int>(s.size())) {
            if (possible(
                    chosen,
                    k)) {
                answer = max(
                    answer,
                    static_cast<int>(chosen.size())
                );
            }

            return;
        }

        search(
            s,
            k,
            index + 1,
            chosen
        );

        chosen.push_back(
            s[index]
        );

        search(
            s,
            k,
            index + 1,
            chosen
        );

        chosen.pop_back();
    }

public:
    int longestPalindromicSubsequence(
        string s,
        int k
    ) {
        answer = 0;

        string chosen;

        search(
            s,
            k,
            0,
            chosen
        );

        return answer;
    }
};
