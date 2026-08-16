class Solution {
public:
    int numMatchingSubseq(
        string s,
        vector<string>& words
    ) {
        array<vector<int>, 26> positions;

        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            positions[s[i] - 'a'].push_back(i);
        }

        int answer = 0;

        for (const string& word : words) {
            int previous = -1;
            bool possible = true;

            for (char character : word) {
                const vector<int>& indices =
                    positions[character - 'a'];

                auto position = upper_bound(
                    indices.begin(),
                    indices.end(),
                    previous
                );

                if (position == indices.end()) {
                    possible = false;
                    break;
                }

                previous = *position;
            }

            if (possible) {
                answer++;
            }
        }

        return answer;
    }
};
