class Solution {
    int answer;

    void search(
        const vector<int>& cookies,
        int index,
        vector<int>& children
    ) {
        if (index ==
            static_cast<int>(cookies.size())) {
            int unfairness =
                *max_element(
                    children.begin(),
                    children.end()
                );

            answer = min(
                answer,
                unfairness
            );

            return;
        }

        for (int child = 0;
             child < static_cast<int>(children.size());
             child++) {
            children[child] +=
                cookies[index];

            search(
                cookies,
                index + 1,
                children
            );

            children[child] -=
                cookies[index];
        }
    }

public:
    int distributeCookies(
        vector<int>& cookies,
        int k
    ) {
        answer =
            numeric_limits<int>::max();

        vector<int> children(k);

        search(
            cookies,
            0,
            children
        );

        return answer;
    }
};
