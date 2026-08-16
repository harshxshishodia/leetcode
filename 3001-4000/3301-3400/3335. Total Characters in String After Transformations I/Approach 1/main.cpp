class Solution {
public:
    int lengthAfterTransformations(
        string s,
        int t
    ) {
        const int MOD =
            1000000007;

        while (t > 0) {
            string next;

            for (char character :
                 s) {
                if (character == 'z') {
                    next.push_back(
                        'a'
                    );

                    next.push_back(
                        'b'
                    );
                } else {
                    next.push_back(
                        character +
                        1
                    );
                }
            }

            s.swap(
                next
            );

            t--;
        }

        return static_cast<int>(
            s.size() %
            MOD
        );
    }
};
