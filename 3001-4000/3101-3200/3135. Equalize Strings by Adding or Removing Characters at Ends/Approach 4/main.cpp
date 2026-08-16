class Solution {
    struct State {
        array<int, 26> next;
        int link;
        int length;

        State() :
            link(-1),
            length(0) {
            next.fill(-1);
        }
    };

public:
    int minOperations(
        string initial,
        string target
    ) {
        vector<State> automaton(
            1
        );

        int last = 0;

        for (char character :
             initial) {
            int current =
                static_cast<int>(
                    automaton.size()
                );

            automaton.push_back(
                State()
            );

            automaton[current].length =
                automaton[last].length +
                1;

            int edge =
                character -
                'a';

            int parent =
                last;

            while (
                parent != -1 &&
                automaton[parent].next[edge] ==
                -1
            ) {
                automaton[parent].next[edge] =
                    current;

                parent =
                    automaton[parent].link;
            }

            if (parent == -1) {
                automaton[current].link =
                    0;
            } else {
                int next =
                    automaton[parent].next[edge];

                if (
                    automaton[parent].length +
                    1 ==
                    automaton[next].length
                ) {
                    automaton[current].link =
                        next;
                } else {
                    int clone =
                        static_cast<int>(
                            automaton.size()
                        );

                    automaton.push_back(
                        automaton[next]
                    );

                    automaton[clone].length =
                        automaton[parent].length +
                        1;

                    while (
                        parent != -1 &&
                        automaton[parent].next[edge] ==
                        next
                    ) {
                        automaton[parent].next[edge] =
                            clone;

                        parent =
                            automaton[parent].link;
                    }

                    automaton[next].link =
                        clone;

                    automaton[current].link =
                        clone;
                }
            }

            last =
                current;
        }

        int state = 0;
        int length = 0;
        int best = 0;

        for (char character :
             target) {
            int edge =
                character -
                'a';

            while (
                state != 0 &&
                automaton[state].next[edge] ==
                -1
            ) {
                state =
                    automaton[state].link;

                length =
                    automaton[state].length;
            }

            if (
                automaton[state].next[edge] !=
                -1
            ) {
                state =
                    automaton[state].next[edge];

                length++;
            } else {
                state =
                    0;

                length =
                    0;
            }

            best = max(
                best,
                length
            );
        }

        return
            static_cast<int>(
                initial.size() +
                target.size()
            ) -
            2 *
            best;
    }
};
