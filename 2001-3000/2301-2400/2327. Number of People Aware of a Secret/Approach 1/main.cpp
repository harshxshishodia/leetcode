class Solution {
public:
    int peopleAwareOfSecret(
        int n,
        int delay,
        int forget
    ) {
        const int MOD =
            1000000007;

        vector<long long> learned(
            n + 1
        );

        learned[1] = 1;

        for (int day = 2;
             day <= n;
             day++) {
            long long newPeople = 0;

            for (int learnedDay = 1;
                 learnedDay < day;
                 learnedDay++) {
                int age =
                    day -
                    learnedDay;

                if (age >= delay &&
                    age < forget) {
                    newPeople +=
                        learned[learnedDay];

                    newPeople %=
                        MOD;
                }
            }

            learned[day] =
                newPeople;
        }

        long long answer = 0;

        for (int learnedDay = 1;
             learnedDay <= n;
             learnedDay++) {
            if (n - learnedDay < forget) {
                answer +=
                    learned[learnedDay];

                answer %=
                    MOD;
            }
        }

        return static_cast<int>(answer);
    }
};
