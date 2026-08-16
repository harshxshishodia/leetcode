class Solution {
    struct Fenwick {
        vector<int> tree;

        Fenwick(int size) :
            tree(size + 1) {}

        int query(int index) {
            int answer = 0;

            while (index > 0) {
                answer = max(
                    answer,
                    tree[index]
                );

                index -=
                    index & -index;
            }

            return answer;
        }

        void update(
            int index,
            int value
        ) {
            while (index < static_cast<int>(tree.size())) {
                tree[index] = max(
                    tree[index],
                    value
                );

                index +=
                    index & -index;
            }
        }
    };

public:
    int bestTeamScore(
        vector<int>& scores,
        vector<int>& ages
    ) {
        vector<pair<int, int>> players;

        for (int i = 0;
             i < static_cast<int>(scores.size());
             i++) {
            players.push_back({
                ages[i],
                scores[i]
            });
        }

        sort(
            players.begin(),
            players.end()
        );

        vector<int> values =
            scores;

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
            static_cast<int>(values.size())
        );

        int answer = 0;

        for (auto [age, score] : players) {
            int rank =
                lower_bound(
                    values.begin(),
                    values.end(),
                    score
                ) -
                values.begin() +
                1;

            int current =
                score +
                fenwick.query(rank);

            fenwick.update(
                rank,
                current
            );

            answer = max(
                answer,
                current
            );
        }

        return answer;
    }
};
