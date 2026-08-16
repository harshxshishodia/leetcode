class Solution {
    struct Node {
        int length;
        long long count;
    };

    Node combine(
        const Node& first,
        const Node& second
    ) {
        if (first.length > second.length) {
            return first;
        }

        if (second.length > first.length) {
            return second;
        }

        if (first.length == 0) {
            return {
                0,
                0
            };
        }

        return {
            first.length,
            first.count + second.count
        };
    }

    struct Fenwick {
        vector<Node> tree;
        Solution* owner;

        Fenwick(
            int size,
            Solution* solution
        ) : tree(size + 1, {0, 0}),
            owner(solution) {}

        void update(
            int index,
            Node value
        ) {
            while (index < static_cast<int>(tree.size())) {
                tree[index] = owner->combine(
                    tree[index],
                    value
                );

                index += index & -index;
            }
        }

        Node query(int index) {
            Node answer = {0, 0};

            while (index > 0) {
                answer = owner->combine(
                    answer,
                    tree[index]
                );

                index -= index & -index;
            }

            return answer;
        }
    };

public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> values = nums;

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

        Fenwick fenwick(
            static_cast<int>(values.size()),
            this
        );

        for (int number : nums) {
            int rank =
                static_cast<int>(
                    lower_bound(
                        values.begin(),
                        values.end(),
                        number
                    ) -
                    values.begin()
                ) +
                1;

            Node previous =
                fenwick.query(rank - 1);

            Node current = {
                previous.length + 1,
                previous.length == 0
                    ? 1
                    : previous.count
            };

            fenwick.update(
                rank,
                current
            );
        }

        Node answer =
            fenwick.query(
                static_cast<int>(values.size())
            );

        return static_cast<int>(answer.count);
    }
};
