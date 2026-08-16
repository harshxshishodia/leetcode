class Solution {
    struct Fenwick {
        vector<int> tree;

        Fenwick(int size) :
            tree(size + 1) {}

        void add(
            int index,
            int value
        ) {
            while (index < static_cast<int>(tree.size())) {
                tree[index] += value;
                index +=
                    index & -index;
            }
        }

        int query(int index) {
            int answer = 0;

            while (index > 0) {
                answer += tree[index];
                index -=
                    index & -index;
            }

            return answer;
        }
    };

public:
    int numTeams(vector<int>& rating) {
        vector<int> values = rating;

        sort(
            values.begin(),
            values.end()
        );

        values.erase(
            unique(
                values.begin(),
                values.end()
            ),
            values.end()
        );

        int size =
            static_cast<int>(values.size());

        Fenwick left(size);
        Fenwick right(size);

        for (int value : rating) {
            int rank =
                lower_bound(
                    values.begin(),
                    values.end(),
                    value
                ) -
                values.begin() +
                1;

            right.add(
                rank,
                1
            );
        }

        long long answer = 0;

        for (int index = 0;
             index < static_cast<int>(rating.size());
             index++) {
            int rank =
                lower_bound(
                    values.begin(),
                    values.end(),
                    rating[index]
                ) -
                values.begin() +
                1;

            right.add(
                rank,
                -1
            );

            int leftSmaller =
                left.query(rank - 1);

            int leftGreater =
                index -
                left.query(rank);

            int rightSmaller =
                right.query(rank - 1);

            int rightGreater =
                static_cast<int>(rating.size()) -
                index -
                1 -
                right.query(rank);

            answer +=
                1LL *
                leftSmaller *
                rightGreater;

            answer +=
                1LL *
                leftGreater *
                rightSmaller;

            left.add(
                rank,
                1
            );
        }

        return static_cast<int>(answer);
    }
};
