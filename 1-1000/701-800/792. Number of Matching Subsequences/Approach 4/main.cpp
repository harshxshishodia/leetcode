class Solution {
public:
    int numMatchingSubseq(
        string s,
        vector<string>& words
    ) {
        array<vector<pair<int, int>>, 26> waiting;

        int answer = 0;

        for (int index = 0;
             index < static_cast<int>(words.size());
             index++) {
            if (words[index].empty()) {
                answer++;
            } else {
                waiting[
                    words[index][0] - 'a'
                ].push_back({
                    index,
                    0
                });
            }
        }

        for (char character : s) {
            int bucket =
                character - 'a';

            vector<pair<int, int>> current =
                move(waiting[bucket]);

            waiting[bucket].clear();

            for (auto [wordIndex, position] : current) {
                position++;

                if (position ==
                    static_cast<int>(words[wordIndex].size())) {
                    answer++;
                } else {
                    waiting[
                        words[wordIndex][position] - 'a'
                    ].push_back({
                        wordIndex,
                        position
                    });
                }
            }
        }

        return answer;
    }
};
