class Solution {
    int answer;

    void search(
        const vector<int>& cookies,
        int index,
        vector<int>& children
    ) {
        if (index ==
            static_cast<int>(cookies.size())) {
            answer = min(
                answer,
                *max_element(
                    children.begin(),
                    children.end()
                )
            );

            return;
        }

        for (int child = 0;
             child < static_cast<int>(children.size());
             child++) {
            if (children[child] +
                cookies[index] >=
                answer) {
                continue;
            }

            bool duplicate = false;

            for (int previous = 0;
                 previous < child;
                 previous++) {
                if (children[previous] ==
                    children[child]) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                continue;
            }

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
        sort(
            cookies.begin(),
            cookies.end(),
            greater<int>()
        );

        answer =
            accumulate(
                cookies.begin(),
                cookies.end(),
                0
            );

        vector<int> children(k);

        search(
            cookies,
            0,
            children
        );

        return answer;
    }
};
