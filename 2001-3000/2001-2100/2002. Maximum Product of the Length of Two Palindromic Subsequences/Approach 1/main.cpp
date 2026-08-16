class Solution {
    int answer = 0;

    bool palindrome(
        const string& value
    ) {
        int left = 0;
        int right =
            static_cast<int>(value.size()) -
            1;

        while (left < right) {
            if (value[left] != value[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    void search(
        const string& s,
        int index,
        string& first,
        string& second
    ) {
        if (index == static_cast<int>(s.size())) {
            if (palindrome(first) &&
                palindrome(second)) {
                answer = max(
                    answer,
                    static_cast<int>(
                        first.size() *
                        second.size()
                    )
                );
            }

            return;
        }

        search(
            s,
            index + 1,
            first,
            second
        );

        first.push_back(
            s[index]
        );

        search(
            s,
            index + 1,
            first,
            second
        );

        first.pop_back();

        second.push_back(
            s[index]
        );

        search(
            s,
            index + 1,
            first,
            second
        );

        second.pop_back();
    }

public:
    int maxProduct(string s) {
        answer = 0;

        string first;
        string second;

        search(
            s,
            0,
            first,
            second
        );

        return answer;
    }
};
