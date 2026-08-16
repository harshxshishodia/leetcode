class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int firstLength = static_cast<int>(s1.size());
        int secondLength = static_cast<int>(s2.size());

        vector<vector<int>> common(
            firstLength + 1,
            vector<int>(secondLength + 1)
        );

        for (int i = 1; i <= firstLength; i++) {
            for (int j = 1; j <= secondLength; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    common[i][j] =
                        common[i - 1][j - 1] +
                        static_cast<unsigned char>(s1[i - 1]);
                } else {
                    common[i][j] = max(
                        common[i - 1][j],
                        common[i][j - 1]
                    );
                }
            }
        }

        int total = 0;

        for (char character : s1) {
            total += static_cast<unsigned char>(character);
        }

        for (char character : s2) {
            total += static_cast<unsigned char>(character);
        }

        return
            total -
            2 * common[firstLength][secondLength];
    }
};
