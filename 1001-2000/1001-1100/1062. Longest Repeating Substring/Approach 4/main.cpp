class Solution {
    struct State {
        int link;
        int length;
        int occurrences;
        array<int, 26> next;

        State() :
            link(-1),
            length(0),
            occurrences(0) {
            next.fill(-1);
        }
    };

public:
    int longestRepeatingSubstring(string s) {
        vector<State> states(
            2 * s.size() + 1
        );

        int size = 1;
        int last = 0;

        for (char character : s) {
            int value =
                character - 'a';

            int current =
                size++;

            states[current].length =
                states[last].length + 1;

            states[current].occurrences = 1;

            int previous =
                last;

            while (previous != -1 &&
                   states[previous].next[value] == -1) {
                states[previous].next[value] =
                    current;

                previous =
                    states[previous].link;
            }

            if (previous == -1) {
                states[current].link = 0;
            } else {
                int target =
                    states[previous].next[value];

                if (states[previous].length + 1 ==
                    states[target].length) {
                    states[current].link =
                        target;
                } else {
                    int clone =
                        size++;

                    states[clone] =
                        states[target];

                    states[clone].length =
                        states[previous].length + 1;

                    states[clone].occurrences = 0;

                    while (previous != -1 &&
                           states[previous].next[value] == target) {
                        states[previous].next[value] =
                            clone;

                        previous =
                            states[previous].link;
                    }

                    states[target].link =
                        clone;

                    states[current].link =
                        clone;
                }
            }

            last = current;
        }

        int maximumLength = 0;

        for (int i = 0; i < size; i++) {
            maximumLength = max(
                maximumLength,
                states[i].length
            );
        }

        vector<int> count(
            maximumLength + 1
        );

        for (int i = 0; i < size; i++) {
            count[states[i].length]++;
        }

        for (int length = 1;
             length <= maximumLength;
             length++) {
            count[length] +=
                count[length - 1];
        }

        vector<int> order(size);

        for (int i = size - 1; i >= 0; i--) {
            order[
                --count[states[i].length]
            ] = i;
        }

        for (int i = size - 1; i > 0; i--) {
            int state =
                order[i];

            int parent =
                states[state].link;

            if (parent >= 0) {
                states[parent].occurrences +=
                    states[state].occurrences;
            }
        }

        int answer = 0;

        for (int i = 1; i < size; i++) {
            if (states[i].occurrences >= 2) {
                answer = max(
                    answer,
                    states[i].length
                );
            }
        }

        return answer;
    }
};
