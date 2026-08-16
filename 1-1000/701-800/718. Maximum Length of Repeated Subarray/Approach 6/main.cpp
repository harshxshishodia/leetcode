class Solution {
    struct State {
        int link;
        int length;
        unordered_map<int, int> next;
    };

    vector<State> states;
    int last;

    void extend(int value) {
        int current =
            static_cast<int>(states.size());

        states.push_back({
            0,
            states[last].length + 1,
            {}
        });

        int previous = last;

        while (previous != -1 &&
               !states[previous].next.count(value)) {
            states[previous].next[value] =
                current;

            previous =
                states[previous].link;
        }

        if (previous == -1) {
            states[current].link = 0;
        } else {
            int nextState =
                states[previous].next[value];

            if (states[previous].length + 1 ==
                states[nextState].length) {
                states[current].link =
                    nextState;
            } else {
                int clone =
                    static_cast<int>(states.size());

                states.push_back(
                    states[nextState]
                );

                states[clone].length =
                    states[previous].length + 1;

                while (previous != -1) {
                    auto found =
                        states[previous].next.find(value);

                    if (found == states[previous].next.end() ||
                        found->second != nextState) {
                        break;
                    }

                    found->second = clone;

                    previous =
                        states[previous].link;
                }

                states[nextState].link =
                    clone;

                states[current].link =
                    clone;
            }
        }

        last = current;
    }

public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        states.clear();

        states.push_back({
            -1,
            0,
            {}
        });

        last = 0;

        for (int value : nums1) {
            extend(value);
        }

        int state = 0;
        int length = 0;
        int answer = 0;

        for (int value : nums2) {
            while (state != 0 &&
                   !states[state].next.count(value)) {
                state =
                    states[state].link;

                length =
                    states[state].length;
            }

            auto found =
                states[state].next.find(value);

            if (found != states[state].next.end()) {
                state =
                    found->second;

                length++;
            } else {
                state = 0;
                length = 0;
            }

            answer = max(
                answer,
                length
            );
        }

        return answer;
    }
};
